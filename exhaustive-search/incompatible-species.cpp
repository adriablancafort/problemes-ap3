#include <iostream>
#include <vector>
using namespace std;

void generate(string& word, vector<bool>& used, const vector<vector<bool>>& compatible, const string& species, int pos) {
    if (pos == word.length()) {
        cout << word << endl;
        return;
    }
    
    for (int i = 0; i < species.length(); i++) {
        if (!used[i] and (pos == 0 or compatible[word[pos-1]][species[i]])) {
            used[i] = true;
            word[pos] = species[i];
            generate(word, used, compatible, species, pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    
    string species(n, ' ');
    for (char& c : species) cin >> c;
    
    vector<vector<bool>> compatible(128, vector<bool>(128, true));
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        compatible[a][b] = compatible[b][a] = false;
    }
    
    string word(n, ' ');
    vector<bool> used(n, false);
    generate(word, used, compatible, species, 0);
}