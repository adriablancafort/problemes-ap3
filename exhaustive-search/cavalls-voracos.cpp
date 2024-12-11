#include <iostream>
#include <vector>
using namespace std;

bool dins_rang(int i, int j, vector<vector<bool>>& sol) {
    int n = sol.size();
    int m = sol[0].size();
    return i >= 0 and i < n and j >= 0 and j < m;
}

int monedes(vector<vector<int>>& tauler, vector<vector<bool>>& sol, int i, int j, int monedes_actuals) {
    if (j == sol[0].size()) return monedes(tauler, sol, i+1, 0, monedes_actuals);

    if (i == sol.size()) {
        return monedes_actuals;
    }
    
    const vector<pair<int,int>> dirs = { {-1,2}, {-1,-2}, {-2,1}, {-2,-1} };
    bool possible = true;
    for (const pair<int,int>& dir : dirs) {
        int n_i = i + dir.first; 
        int n_j = j + dir.second;
        if (dins_rang(n_i, n_j, sol) and sol[n_i][n_j]) {
            possible = false;
            break;
        }
    }

    sol[i][j] = false;
    int cas_1 = monedes(tauler, sol, i, j+1, monedes_actuals);

    if (possible) {
        sol[i][j] = true;
        int cas_2 = monedes(tauler, sol, i, j+1, monedes_actuals + tauler[i][j]);
        sol[i][j] = false;
        return max(cas_1, cas_2);
    }
    
    return cas_1;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> tauler(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tauler[i][j];
            }
        }

        vector<vector<bool>> sol(n, vector<bool>(m, false));
        cout << monedes(tauler, sol, 0, 0, 0) << endl;
    }
    return 0;
}