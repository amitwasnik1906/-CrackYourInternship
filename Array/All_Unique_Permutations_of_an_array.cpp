#include<bits/stdc++.h>
using namespace std;

class Solution {
    void f(vector<int>& nums, vector<vector<int>>& ans, int ind) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int, int> mp;
        for (int i = ind; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                continue;
            } else {
                mp[nums[i]]++;
                swap(nums[i], nums[ind]);
                f(nums, ans, ind + 1);
                swap(nums[i], nums[ind]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        f(nums, ans, 0);
        return ans;
    }
};

// T.C. : O(N*log(N)) + O(N*N!)
// S.C. : O(N)