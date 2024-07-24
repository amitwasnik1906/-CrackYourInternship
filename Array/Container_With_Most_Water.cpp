#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0;
        int j = n - 1;
        
        while (i < j) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};

// T.C. : O(N)
// S.C. : O(1)