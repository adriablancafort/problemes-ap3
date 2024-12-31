#include <iostream>
#include <vector>
using namespace std;

int findLCS(const vector<int>& arthur, const vector<int>& bob, vector<vector<int>>& dp, int i, int j) {
    if (i == 0 || j == 0) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];
    
    if (arthur[i-1] == bob[j-1]) {
        dp[i][j] = 1 + findLCS(arthur, bob, dp, i-1, j-1);
    } else {
        dp[i][j] = max(findLCS(arthur, bob, dp, i-1, j),
                       findLCS(arthur, bob, dp, i, j-1));
    }
    
    return dp[i][j];
}

int main() {
    int M, N;
    while (cin >> M >> N) {
        vector<int> arthur(M);
        vector<int> bob(N);
        
        for (int i = 0; i < M; i++) cin >> arthur[i];
        for (int i = 0; i < N; i++) cin >> bob[i];
        
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, -1));
        
        cout << findLCS(arthur, bob, dp, M, N) << endl;
    }
    return 0;
}