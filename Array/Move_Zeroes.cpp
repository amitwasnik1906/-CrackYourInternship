#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        while (zero < n && nums[zero] != 0) {
            zero++;
        }

        for (int i = zero + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[zero]);
                zero++;
            }
        }
    }
};

// T.C. : O(N)
// S.C. : O(1)