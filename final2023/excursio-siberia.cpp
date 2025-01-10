#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio() const {
        return static_cast<double>(value) / weight;
    }
};

bool compareRatio(const Item& a, const Item& b) {
    return a.ratio() > b.ratio();
}

double maxKilocalories(int W, vector<Item>& cans, vector<Item>& sausages) {
    sort(sausages.begin(), sausages.end(), compareRatio);

    vector<double> dp(W + 1, 0.0);
    for (const auto& can : cans) {
        for (int w = W; w >= can.weight; --w) {
            dp[w] = max(dp[w], dp[w - can.weight] + can.value);
        }
    }

    double maxKcal = *max_element(dp.begin(), dp.end());
    double remainingWeight = W - maxKcal;

    for (const auto& sausage : sausages) {
        if (remainingWeight <= 0) break;
        if (sausage.weight <= remainingWeight) {
            maxKcal += sausage.value;
            remainingWeight -= sausage.weight;
        } else {
            maxKcal += sausage.ratio() * remainingWeight;
            remainingWeight = 0;
        }
    }

    return maxKcal;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int W;
    while (cin >> W) {
        int z;
        cin >> z;
        vector<Item> cans(z);
        for (int i = 0; i < z; ++i) cin >> cans[i].value >> cans[i].weight;

        int r;
        cin >> r;
        vector<Item> sausages(r);
        for (int i = 0; i < r; ++i) cin >> sausages[i].value >> sausages[i].weight;

        cout << maxKilocalories(W, cans, sausages) << endl;
    }

    return 0;
}