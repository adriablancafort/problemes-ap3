#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int suma(vector<int>& peluixos, int n) {
    sort(peluixos.begin(), peluixos.end());

    int suma = 0;
    for (int i = 0; i < 3*n; i++) {
        if (i % 3 != 0) {
            // Nomes agaffem els 2 elements mes cars de cada 3
            suma += peluixos[i];
        }
    }
    return suma;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> peluixos(3*n);
        for (int i = 0; i < 3*n; i++) {
            cin >> peluixos[i];
        }
        cout << suma(peluixos, n) << endl;
    }
}