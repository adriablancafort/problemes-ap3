#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUM = 300;
const int UNDEF = -1;

int rec(int n, vector<int>& cache) {
    if (cache[n] != UNDEF) return cache[n];

    if (n == 1) {
        cache[n] = 1;
        return 1;
    }

    cache[n] = n + rec(n - 1, cache);
    return cache[n];
}

int letterToIndex(char letter) {
    return letter - 'A' + 1;
}

int main() {
    int sum = 0;
    char letter;
    vector<int> cache(MAX_NUM + 1, UNDEF);

    while (cin >> letter) {
        int inp = letterToIndex(letter);
        sum += rec(inp, cache);
        cout << sum << endl;
    }
    return 0;
}