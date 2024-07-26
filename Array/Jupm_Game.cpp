#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndx = 0;

        for (int i = 0; i < n; i++) {
            if (maxIndx < i) return false;

            maxIndx = max(maxIndx, i + nums[i]);
            if (maxIndx >= n) return true;
        }

        return true;
    }
};

// T.C. : O(N)
// S.C. : O(1)