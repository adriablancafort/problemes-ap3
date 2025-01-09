#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct moli {
    int autonomia;
    int productivitat;
    int consum;

    double eficiencia() const {
        return static_cast<double>(productivitat) / consum;
    }
};

double consumMinim(vector<moli>& molins, int demanda) {
    sort(molins.begin(), molins.end(), [](const moli& a, const moli& b) {
        return a.eficiencia() > b.eficiencia();
    });

    double consumTotal = 0.0;
    for (const auto& moli : molins) {
        int produccioPossible = moli.autonomia * moli.productivitat;
        if (demanda <= produccioPossible) {
            consumTotal += static_cast<double>(demanda) / moli.productivitat * moli.consum;
            break;
        } else {
            consumTotal += moli.autonomia * moli.consum;
            demanda -= produccioPossible;
        }
    }

    return consumTotal;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    while (cin >> n) {
        vector<moli> molins(n);
        for (int i = 0; i < n; ++i) cin >> molins[i].autonomia;
        for (int i = 0; i < n; ++i) cin >> molins[i].productivitat;
        for (int i = 0; i < n; ++i) cin >> molins[i].consum;

        int demanda;
        cin >> demanda;

        cout << consumMinim(molins, demanda) << endl;
    }

    return 0;
}