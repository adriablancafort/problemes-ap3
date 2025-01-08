#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printSubset(vector<string>& paraules, vector<int>& particions, int p) {
    for (int i = 0; i < p; i++) {
        cout << "subset " << i + 1 << ": {";
        bool first = true;
        for (int j = 0; j < paraules.size(); j++) {
            if (particions[j] == i) {
                if (first) first = false;
                else cout << ",";
                cout << paraules[j];
            }
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void colocar(vector<string>& paraules, vector<int>& particions, int p, int pos) {
    if (pos == paraules.size()) {
        printSubset(paraules, particions, p);
        return;
    }

    for (int i = 0; i < p; i++) {
        particions[pos] = i;
        colocar(paraules, particions, p, pos + 1);
    }
}

int main() {
    int n, p;
    cin >> n;
    vector<string> paraules(n);
    for (int i = 0; i < n; i++) {
        cin >> paraules[i];
    }
    cin >> p;
    vector<int> particions(n);
    colocar(paraules, particions, p, 0);
}