#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_subset(const vector<string>& words, const vector<bool>& choosen) {
    cout << "{";
    bool first = true;
    for (int i = 0; i < words.size(); i++) {
        if(choosen[i]) {
            if (first) first = false;
            else cout << ",";
            cout << words[i];
        }
    }
    cout << "}" << endl;
}

void rec(const vector<string>& words, vector<bool>& choosen, int pos, int remaining) {
    if(remaining == 0) {
        print_subset(words, choosen);
        return;
    }
    
    if(pos < words.size() and words.size() - pos >= remaining) {
        choosen[pos] = true;
        rec(words, choosen, pos + 1, remaining - 1);
        
        choosen[pos] = false;
        rec(words, choosen, pos + 1, remaining);
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> words(n);
    for(string &word : words) cin >> word;

    vector<bool> choosen(n, false);
    rec(words, choosen, 0, m);

    return 0;
}