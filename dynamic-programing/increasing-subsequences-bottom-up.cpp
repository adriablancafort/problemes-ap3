#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rec(string& seq, int i, vector<long long>& memo) {
    if (memo[i] != -1) return memo[i];
    long long sum = 0;
    for (int j = 0; j < i; j++) {
        if (seq[j] < seq[i]) {
            sum += 1 + rec(seq, j, memo);
        }
    }
    memo[i] = sum;
    return sum;
}

int main() {
    string seq;
    while (cin >> seq) {
        int n = int(seq.size());
        vector<long long> memo(n, -1);
        long long total = 0;
        for (int i = 1; i < n; i++) {
            total += rec(seq, i, memo);
        }
        cout << total << endl;
    }
}