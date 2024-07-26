#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int index = nums1.size()-1;

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[index--] = nums1[i--];
            }
            else{
                nums1[index--] = nums2[j--];
            }
        }

        while(i>=0){
            nums1[index--] = nums1[i--];
        }
        while(j>=0){
            nums1[index--] = nums2[j--];
        }
    }
};

// T.C. : O(M+N)
// S.C. : O(1)



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(nums1.begin(), nums1.begin()+m);
        int i = 0, j = 0, index = 0;

        while(i<m && j<n){
            if(temp[i] < nums2[j]){
                nums1[index++] = temp[i++];
            }
            else{
                nums1[index++] = nums2[j++];
            }
        }

        while(i<m){
            nums1[index++] = temp[i++];
        }
        while(j<n){
            nums1[index++] = nums2[j++];
        }
    }
};

// T.C. : O(M+N)
// S.C. : O(M)
