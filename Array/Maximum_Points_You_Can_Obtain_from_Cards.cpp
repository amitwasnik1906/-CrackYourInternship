#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;
        int sum = 0;

        for (int i = n - k; i < n + k; i++) {
            sum += cardPoints[i % n];
            if (i < n - 1)
                continue;

            ans = max(ans, sum);
            sum -= cardPoints[(i - k + 1) % n];
        }

        return ans;
    }
};

// T.C. : O(N)
// S.C. : O(1)