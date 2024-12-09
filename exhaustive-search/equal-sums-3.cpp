#include <iostream>
#include <vector>
using namespace std;

void print_subset(vector<int> &numbers, vector<bool> &choosen) {
    cout << "{";
    bool first = true;
    for(int i = 0; i < numbers.size(); i++) {
        if (choosen[i]){
            if (first) first = false;
            else cout << ",";
            cout << numbers[i];
        }
    }
    cout << "}" << endl;
}

void rec(vector<int> &numbers, vector<bool> &choosen, int total_sum, int current_sum, int pos, int new_subset) {
    if (current_sum == total_sum and new_subset) print_subset(numbers, choosen);

    if (pos < numbers.size()) {
        choosen[pos] = true;
        rec(numbers, choosen, total_sum, current_sum + numbers[pos], pos + 1, true);

        choosen[pos] = false;
        rec(numbers, choosen, total_sum, current_sum, pos + 1, false);
    }
}

int main() {
    int total_sum, n;
    cin >> total_sum >> n;

    vector<int> numbers(n);
    for(int &number : numbers) cin >> number;

    vector<bool> choosen(n, false);
    rec(numbers, choosen, total_sum, 0, 0, true);

    return 0;
}