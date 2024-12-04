#include <iostream>
#include <vector>
using namespace std;

void print_subset(const vector<int>& nums, const vector<bool>& chosen) {
    cout << "{";
    bool first = true;
    for (int i = 0; i < nums.size(); i++) {
        if (chosen[i]) {
            if (first) first = false;
            else cout << ",";
            cout << nums[i];
        }
    }
    cout << "}" << endl;
}

void rec(const vector<int>& nums, vector<bool>& chosen, 
         const int total_sum, int current_sum, int pos, bool new_subset) {
    if (current_sum == total_sum and new_subset) print_subset(nums, chosen);

    if (pos < nums.size()) {
        chosen[pos] = true;
        rec(nums, chosen, total_sum, current_sum + nums[pos], pos + 1, true);
        
        chosen[pos] = false;
        rec(nums, chosen, total_sum, current_sum, pos + 1, false);
    }
}

int main() {
    int total_sum, n;
    cin >> total_sum >> n;

    vector<int> nums(n);
    for (int& num : nums) cin >> num;

    vector<bool> chosen(n, false);

    rec(nums, chosen, total_sum, 0, 0, true);
    return 0;
}