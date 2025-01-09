#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void findSelections(int n, int m, const vector<set<int>>& friends, int k, vector<int>& current, int start, vector<vector<int>>& results) {
    if (current.size() > k) return;

    bool allSatisfied = true;
    for (const auto& friendSongs : friends) {
        bool satisfied = false;
        for (int song : current) {
            if (friendSongs.count(song)) {
                satisfied = true;
                break;
            }
        }
        if (!satisfied) {
            allSatisfied = false;
            break;
        }
    }

    if (allSatisfied) {
        results.push_back(current);
        return;
    }

    for (int i = start; i < n; ++i) {
        current.push_back(i);
        findSelections(n, m, friends, k, current, i + 1, results);
        current.pop_back();
    }
}

int main() {
    int n, m, k;
    cin >> n >> m;

    vector<set<int>> friends(m);
    for (int i = 0; i < m; ++i) {
        int si;
        cin >> si;
        for (int j = 0; j < si; ++j) {
            int song;
            cin >> song;
            friends[i].insert(song);
        }
    }

    cin >> k;

    vector<vector<int>> results;
    vector<int> current;
    findSelections(n, m, friends, k, current, 0, results);

    for (const auto& result : results) {
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) cout << ",";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}