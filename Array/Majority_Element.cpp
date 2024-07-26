#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int el = nums[0];
        for(int i = 1; i<n; i++){
            if(el == nums[i]){
                cnt++;
            }
            else if(cnt == 0){
                cnt++;
                el = nums[i];
            }
            else{
                cnt--;
            }
        }

        int count = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == el) count++;
        }

        return count >= n/2 ? el: -1;
    }
};

// T.C. : O(2*N)
// S.C. : O(1)