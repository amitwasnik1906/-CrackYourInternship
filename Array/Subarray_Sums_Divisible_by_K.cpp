#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0) {
                rem = k + rem;
            }

            if (mp[rem] > 0)
                cnt += mp[rem];
                
            mp[rem]++;
        }

        return cnt;
    }
};

// T.C. : O(N)
// S.C. : O(N)