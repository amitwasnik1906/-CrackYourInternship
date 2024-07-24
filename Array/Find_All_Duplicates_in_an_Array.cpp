#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result; 
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; 
            
            if (nums[index] < 0) { // If the number at index is negative, it means it's seen before
                result.push_back(index + 1); // Add the duplicate number to the result
            } else {
                nums[index] = -nums[index]; // Mark the number as seen by negating it
            }
        }
        return result; 
    }
};

// T.C. : O(N)
// S.C. : O(1)