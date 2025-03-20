#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Kadane's Algorithm

int maxSubarraySum(vector<int>& nums) {
    int sum = 0, maxSum = -1e9;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum <= 0) sum = 0;
    }
    return maxSum;
}


int main() {
    int size = 5;
    vector<int> nums = {1, 2, 3, -2, 5};
    cout << maxSubarraySum(nums) << endl;
}

// N = 5
// Arr[] = {1,2,3,-2,5}
// O(N)