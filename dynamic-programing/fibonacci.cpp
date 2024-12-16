#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& memo) {
    if (memo[n] != -1) return memo[n];
    
    int result;
    if (n == 1 or n == 2) {
        result = 1;
    } else {
        result = fib(n - 1, memo) + fib(n - 2, memo);
    }

    memo[n] = result;
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << fib(n, memo) << endl;
    return 0;
}