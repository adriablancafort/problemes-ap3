#include <iostream>
using namespace std;

void print_word(vector<char> word) {
    for (char &letter : word) cout << letter;
    cout << endl;
}

void rec(vector<char> consonants, vector<char> vowels, vector<bool> used_cons, vector<bool> used_vowels, vector<char> current_word, int n, int pos) {
    if (pos == 2*n) {
        print_word(current_word);
        return;
    }
    
    if (pos % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (!used_cons[i]) {
                used_cons[i] = true;
                current_word[pos] = consonants[i];
                rec(consonants, vowels, used_cons, used_vowels, current_word, n, pos + 1);
                used_cons[i] = false;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!used_vowels[i]) {
                used_vowels[i] = true;
                current_word[pos] = vowels[i];
                rec(consonants, vowels, used_cons, used_vowels, current_word, n, pos + 1);
                used_vowels[i] = false;
            }
        }
    }

}

int main() {
    int n;
    cin >> n;

    vector<char> consonants(n);
    vector<char> vowels(n);

    for (char& cons : consonants) cin >> cons;
    for (char& vowel : vowels) cin >> vowel;

    vector<bool> used_cons(n, false);
    vector<bool> used_vowels(n, false);
    vector<char> current_word(2*n);

    rec(consonants, vowels, used_cons, used_vowels, current_word, n, 0);
    return 0;
}