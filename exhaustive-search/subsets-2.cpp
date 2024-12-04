#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VB = vector<bool>;
using VS = vector<string>;

int n;
VS llista;
VB contained;

void print_subset() {
	bool first = true;
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (contained[i]) {
			if (first) first = false;
			else cout << ","; 
			cout << llista[i];
		}
	}
	cout << "}" << endl;
}

void allperms(int i, int m) {
	if (m < 0) return;
    // Espais que queden menors als uns que ens falta posar
    if (n - i < m) return;
	
	if (i == n) {
		if (m == 0) print_subset();
	} else {
		contained[i] = false; allperms(i + 1, m);
		contained[i] = true; allperms(i + 1, m - 1);
	}
}

int main() {
    int m;

    cin >> m >> n;

    contained = VB(n);
    llista = VS(n);

    for (string &e : llista) {
        cin >> e;
    }

    allperms(0, m);

    return 0;
}