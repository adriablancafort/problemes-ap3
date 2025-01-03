#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numCoins;
    while (cin >> numCoins) {
        // Read coin values and sort them
        vector<int> coins(numCoins);
        for (int i = 0; i < numCoins; ++i) cin >> coins[i];
        sort(coins.begin(), coins.end());  // Sort coins in ascending order

        int targetAmount;
        cin >> targetAmount;

        // dp array: stores the coin value used at each amount
        // -1 means amount is not possible to achieve
        vector<int> dp(targetAmount, -1);

        // currentCoinIndex tracks which coin we're currently considering
        int currentCoinIndex = 0;

        // Fill dp array from smallest coin value to target amount
        for (int amount = coins[0]-1; amount < targetAmount; ++amount) {
            if (amount == coins[currentCoinIndex]-1) {
                // If current amount matches a coin value, use that coin
                dp[amount] = coins[currentCoinIndex];
                if (currentCoinIndex < numCoins-1) ++currentCoinIndex;
            }
            else {
                // Try to use previous coins if possible
                for (int j = currentCoinIndex; j >= 0; --j) {
                    // Check if we can use current coin
                    // by seeing if (amount - coinValue) was possible
                    if (amount >= coins[j] && dp[amount-coins[j]] > 0) {
                        dp[amount] = coins[j];
                        break;  // Found a valid coin, stop searching
                    }
                }
            }
        }

        // If target amount is not possible
        if (dp[targetAmount-1] == -1) cout << -1 << endl;
        else {
            // Reconstruct solution by backtracking
            int remainingAmount = targetAmount-1;
            bool firstCoin = true;
            while (remainingAmount >= 0) {
                if (firstCoin) firstCoin = false;
                else cout << ',';
                cout << dp[remainingAmount];
                remainingAmount -= dp[remainingAmount];
            }
            cout << endl;
        }
    }
}