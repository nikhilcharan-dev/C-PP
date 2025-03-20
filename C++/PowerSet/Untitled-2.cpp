#include <bits/stdc++.h>
using namespace std;


// void bubbleSort(vector<int>& nums, int start, int end) {
//     if(start == end) return;

//     int swaps = 0;
//     for(int i = start; i < end; i++) {
//         if(nums[i] > nums[i + 1]) {
//             swap(nums[i], nums[i + 1]);
//             swaps++;
//         }
//     }
    
//     if(swaps) {
//         bubbleSort(nums, start, end - 1);
//     } else {
//         return;
//     }
// }


void bubbleSort(vector<int>& nums, int n, int i) {
    if(n == 0 || i == n - 1) return;

    if(nums[i] > nums[i + 1]) swap(nums[i], nums[i + 1]);
    
    bubbleSort(nums, n, i + 1);

    bubbleSort(nums, n - 1, 0);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    bubbleSort(nums, nums.size(), 0);

    for(auto& num: nums) cout << num << " ";
    return 0;
}