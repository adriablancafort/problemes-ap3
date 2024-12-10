#include <iostream>
#include <vector>
using namespace std;

void print_word(const vector<char>& word) {
    for (char c : word) cout << c;
    cout << endl;
}

void generate_words(int n, const vector<char>& consonants, const vector<char>& vowels, vector<bool>& used_cons, vector<bool>& used_vowels, vector<char>& current_word, int pos) {
    if (pos == 2*n) {
        print_word(current_word);
        return;
    }
    
    if (pos % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (!used_cons[i]) {
                used_cons[i] = true;
                current_word[pos] = consonants[i];
                generate_words(n, consonants, vowels, used_cons, used_vowels, current_word, pos + 1);
                used_cons[i] = false;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!used_vowels[i]) {
                used_vowels[i] = true;
                current_word[pos] = vowels[i];
                generate_words(n, consonants, vowels, used_cons, used_vowels, current_word, pos + 1);
                used_vowels[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> consonants(n);
    for (char &consonant : consonants) cin >> consonant;

    vector<char> vowels(n);
    for (char &vowel : vowels) cin >> vowel;

    vector<bool> used_cons(n, false);
    vector<bool> used_vowels(n, false);
    vector<char> current_word(2*n);
    generate_words(n, consonants, vowels, used_cons, used_vowels, current_word, 0);
    return 0;
}