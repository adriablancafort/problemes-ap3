#include <iostream>
#include <vector>
using namespace std;

long long correctExpressions(vector<long long>& dp, int n, int m) {
    if (dp[n] != -1) return dp[n];
    if (n == 0) return m;
    
    if (n % 2 == 1) {
        dp[n] = 0;
    } else {
        dp[n] = correctExpressions(dp, n-2, m);
        
        for (int n1 = 0; n1 <= n-6; n1 += 2) {
            int n2 = n - n1 - 6;
            dp[n] += correctExpressions(dp, n1, m) * correctExpressions(dp, n2, m);
        }
    }
    
    return dp[n];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<long long> dp(n, -1);
        cout << correctExpressions(dp, n-1, m) << endl;
    }
}