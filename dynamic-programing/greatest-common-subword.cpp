#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_alphabetically_smaller(string& w1, int i, int maxindex, int maxsize) {
    for (int k = 0; k < maxsize; ++k) {
        if (w1[i - maxsize + k] < w1[maxindex - maxsize + k]) return true;
        if (w1[i - maxsize + k] > w1[maxindex - maxsize + k]) return false;
    }
    return false;
}

int main() {
	string w1, w2;
	while (cin >> w1 >> w2) {
		int n = w1.size();
		int m = w2.size();
		vector<vector<int> > mat(n+1, vector<int> (m+1, 0));
		int maxsize = 0;
        int maxindex = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
                // check all letters that match and add 1 to the previous match count
				if(w1[i-1] == w2[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
                // if the current match is bigger than the previous, update maxsize and maxindex.
				if (mat[i][j] > maxsize) {
                    maxsize = mat[i][j];
                    maxindex = i;
                // if the current match is equal to the previous, check if the current word is lexicographically smaller than the previous.
                } else if (mat[i][j] == maxsize) {
                    if (is_alphabetically_smaller(w1, i, maxindex, maxsize)) {
                        maxindex = i;
                    }
                }
			}
		}
        cout << w1.substr(maxindex - maxsize, maxsize) << endl;
	}
}