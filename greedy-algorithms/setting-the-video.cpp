#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countEpisodes(vector<pair<int, int>>& intervals, int n) {
    sort(intervals.begin(), intervals.end(), 
        [](const auto& a, const auto& b) { 
            return a.second < b.second; 
        });

    int count = 1;
    int end = intervals[0].second;
    for (int i = 1; i < n; i++) {
        if (intervals[i].first > end) {
            // No se solapen
            end = intervals[i].second;
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    while(cin >> n) {
        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        cout << countEpisodes(intervals, n) << endl;
    }
}