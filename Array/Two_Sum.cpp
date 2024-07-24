#include<bits/stdc++.h>
using namespace std;

// Pattern 1 : return numbers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0; 
        int j = nums.size()-1;
        
        while(i<j) {
            if(nums[i] + nums[j] == target){
                return {nums[i], nums[j]};
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }

        return {-1, -1};
    }
};

// T.C. : O(N*log(N)) + O(N)
// S.C. : O(1)



// Pattern 2 : return indices
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};

// T.C. : O(N)
// S.C. : O(N)
