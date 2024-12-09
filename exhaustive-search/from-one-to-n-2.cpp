#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& perm) {
    cout << "(";
    for (int i = 0; i < perm.size(); ++i) {
        if (i != 0) cout << ",";
        cout << perm[i] + 1;
    }
    cout << ")" << endl;
}

bool has_single_cycle(const vector<int>& perm) {
    vector<bool> visited(perm.size(), false);
    int pos = 0;
    int count = 0;
    
    do {
        if (visited[pos]) return false;
        visited[pos] = true;
        count++;
        pos = perm[pos];
    } while (pos != 0);
    
    return count == perm.size();
}

void permute(vector<int>& perm, vector<bool>& used, int pos) {
    if (pos == perm.size()) {
        if (has_single_cycle(perm)) {
            write(perm);
        }
        return;
    }
    
    for (int i = 0; i < perm.size(); ++i) {
        if (used[i]) {
            used[i] = false;
            perm[pos] = i;
            permute(perm, used, pos + 1);
            used[i] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> perm(n);
    vector<bool> used(n, true);
    permute(perm, used, 0);
    return 0;
}