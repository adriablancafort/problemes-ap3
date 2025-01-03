#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countIntervals(vector<int>& nums, int n, int k) {
    sort(nums.begin(), nums.end());
    int count = 1;
    int max = nums[0] + k;
    for (int i = 0; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i] + k;
            count++;
        }
    }
    return count;
}

int main() {
    int k;
    while(cin >> k) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << countIntervals(nums, n, k) << endl;
    }
}