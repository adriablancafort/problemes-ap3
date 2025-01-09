#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double maxim(const vector<double>& nombres) {
    int n = nombres.size();
    vector<double> dp(n);

    dp[0] = nombres[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i-1] + nombres[i], dp[i-1] * nombres[i]);
    }

    return dp[n-1];
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    while(cin >> n) {
        vector<double> nombres(n);
        for(double& nombre : nombres) cin >> nombre;
        cout << maxim(nombres) << endl;
    }
}