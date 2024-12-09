#include <iostream>
#include <vector>
using namespace std;

void print_numbers(const vector<int>& numbers) {
    cout << "(";
    for (int i = 0; i < numbers.size(); i++) {
        if (i != 0) cout << ",";
        cout << numbers[i] + 1;
    }
    cout << ")" << endl;
}

void permute(vector<int>& numbers, vector<bool>& used, int pos, int inversions, int k) {
    int n = numbers.size();
    
    if (k < inversions || k > inversions + ((n-pos)*(n-pos-1))/2) return;
    
    if (pos == n) {
        print_numbers(numbers);
        return;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            numbers[pos] = i;
            permute(numbers, used, pos + 1, inversions + count, k);
            used[i] = false;
            ++count;
        }
    }
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> numbers(n);
        vector<bool> used(n, false);
        permute(numbers, used, 0, 0, k);
    }
    return 0;
}