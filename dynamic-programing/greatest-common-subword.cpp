#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonSubword(string& w1, string& w2) {
    int n1 = w1.size();
    int n2 = w2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int maxLength = 0;
    vector<string> longestSubwords;

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (w1[i - 1] == w2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    longestSubwords.clear();
                    longestSubwords.push_back(w1.substr(i - maxLength, maxLength));
                } else if (dp[i][j] == maxLength) {
                    longestSubwords.push_back(w1.substr(i - maxLength, maxLength));
                }
            }
        }
    }

    if (longestSubwords.empty()) return "";
    sort(longestSubwords.begin(), longestSubwords.end());
    return longestSubwords[0];
}

int main() {
    string w1, w2;
    while (cin >> w1 >> w2) {
        cout << longestCommonSubword(w1, w2) << endl;
    }
}