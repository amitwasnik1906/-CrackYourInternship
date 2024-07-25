#include<bits/stdc++.h>
using namespace std;

// using Prefix sum
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int sum = 0;
        int cnt = 0;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum+= nums[i];
            int rem = sum - k;

            if(mp.find(rem) != mp.end()){
                cnt+= mp[rem];
            }

            mp[sum]++;
        }

        return cnt;
    }
};

// T.C. : O(N)
// S.C. : O(N)

/*
The short answer is because of the presence of negative elements in the array
For example: array [1,2,-3,1,2,-3] with k = 0
here subarray A:[1,2,-3] and subarray B: [1,2,-3] are subarray with sum = 0.
Now Sliding Window will take into the account A and B parts separately, and it will miss the subarray,
which happens to be A + B, which is the whole array. This problem can be reproduced in larger settings 
and any other k values. The idea is that sliding window is constrained that the left window cannot move
to the left, since normally sliding window solutions move the window all the way to the right.

If we force ourselves to use the sliding window technique, when we are at the 4th element of the array, 
which is the start of subarray B, we would need to check every element on the left side to make sure the 
above situation does not happen. And therefore we would have to keep extending the left window leftward 
until the start of the array. If we have written the program this way, Yes we are using sliding window, 
and it should also give us the correct result. However, it is easily recognizable that what we are doing 
now is essentially the brute force approach, because we are checking every left element for every item 
that can be a right window. And in a "noraml" sliding window algorithm, we never do this, so we cannot 
use sliding window for this problem.

TLDR: negative elements made sliding window unusable, consider [1,2,-3,1,2,-3] with k = 0
sliding windw would identify two [1,2,-3] but miss the whole array which also sum to 0
*/

