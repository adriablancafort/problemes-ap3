#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<vector<long long>>>> memo;

long long rec(int z, int u, int cons_z, int cons_u) {
    if (z < 0 or u < 0) return 0;                      // Check bounds first
    if (cons_z >= 2 or cons_u >= 3) return 0;         // Check valid sequence
    if (z == 0 and u == 0) return 1;                  // Base case

    if (memo[z][u][cons_z][cons_u] != -1) return memo[z][u][cons_z][cons_u];

    memo[z][u][cons_z][cons_u] = rec(z-1, u, cons_z+1, 0) + rec(z, u-1, 0, cons_u+1);
    return memo[z][u][cons_z][cons_u];
}

int main() {
    int z, u;
    while(cin >> z >> u) {
        memo = vector<vector<vector<vector<long long>>>>(z+1, vector<vector<vector<long long>>>(u+1, vector<vector<long long>>(3, vector<long long>(4, -1))));
        cout << rec(z, u, 0, 0) << endl;
    }
}