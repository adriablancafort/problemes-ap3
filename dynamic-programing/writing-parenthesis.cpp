#include <iostream>
#include <vector>

using namespace std;

const int UNDEF = -1;
const int MAX_NUM = 67;

long int p (int n, vector<long int>& cache) {
    if (cache[n] != UNDEF) return cache[n];

    if (n == 0) {
        cache[n] = 1; 
        return 1;
    }

    long int res = 0;
    for (int i = 2; i <= n; ++i) {
        res += p(i-2,cache)*p(n-i,cache);
    }
    cache[n] = res;
    return res;
}
  

int main ( ){
    int n;
    vector<long int> cache(MAX_NUM + 1,UNDEF);
    
    while (cin >> n) {
        cout << p(n,cache) << endl;
    }
}