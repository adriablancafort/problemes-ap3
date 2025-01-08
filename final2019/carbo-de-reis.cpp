#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductivity(vector<vector<int>>& miners, int pressupost, int limitPes) {
    sort(miners.begin(), miners.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return (double)a[0]/a[1] > (double)b[0]/b[1];
        }
    );

    int totalProd = 0;
    int totalCost = 0;
    int totalWeight = 0;

    for (int i = 0; i < miners.size(); i++) {
        if (totalCost + miners[i][1] <= pressupost && totalWeight + miners[i][2] <= limitPes) {
            totalProd += miners[i][0];
            totalCost += miners[i][1];
            totalWeight += miners[i][2];
        }
    }

    return totalProd;
}

int main() {
    int n, pressupost, limitPes;
    while (cin >> n >> pressupost >> limitPes) {
        vector<vector<int>> miners(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> miners[i][0]; // productivitat
            cin >> miners[i][1]; // cost
            cin >> miners[i][2]; // pes
        }
        cout << maxProductivity(miners, pressupost, limitPes) << endl;
    }
}