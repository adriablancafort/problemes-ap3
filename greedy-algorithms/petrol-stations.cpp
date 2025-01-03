#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countStations(vector<int>& stations, int n, int x, int D) {
    sort(stations.begin(), stations.end());
    
    int count = 0;          // Number of stops
    int currentPos = 0;     // Current position
    int lastStopIndex = -1; // Index of last station where we stopped
    int i = 0;             // Current station being considered
    
    while (currentPos + x < D) {
        int nextStop = -1;
        
        // Find furthest reachable station
        while (i < n && stations[i] <= currentPos + x) {
            nextStop = i;
            i++;
        }

        // Make stop at the furthest reachable station
        currentPos = stations[nextStop];
        lastStopIndex = nextStop;
        count++;
    }
    
    return count;
}

int main() {
    int x, D, n;
    while(cin >> x >> D >> n) {
        vector<int> stations(n);
        for (int i = 0; i < n; i++) cin >> stations[i];
        cout << countStations(stations, n, x, D) << endl;
    }
}