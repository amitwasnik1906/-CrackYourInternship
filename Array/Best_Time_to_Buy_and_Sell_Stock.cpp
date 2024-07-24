#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
            ans = max(ans, prices[i] - mini);
        }
        return ans;
    }
};

// T.C. : O(N)
// S.C. : O(1)