#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = (right[i] - left[i] - 1) * heights[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};

// T.C. : O(N)
// S.C. : O(3*N)



