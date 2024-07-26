#include<bits/stdc++.h>
using namespace std;

class Solution {
    void merge(vector<int>& nums, int s, int mid, int e, int &cnt) {
        vector<int> temp;
        int i = s; 
        int j = mid+1;

        while(i<=mid && j<=e){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }

        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=e){
            temp.push_back(nums[j++]);
        }

        i = s;
        j = mid+1;

        while(i<=mid){
            if(j<=e && nums[i] > (long long) 2*nums[j]){
                j++;
            }
            else{
                cnt+= j-mid-1;
                i++;
            }
        }

        int x = 0;
        for(int k = s; k<=e; k++){
            nums[k] = temp[x++];
        }

    }

    void mergeSort(vector<int>& nums, int s, int e, int &cnt) {
        // base case
        if (s >= e) {
            return;
        }
        int mid = (s + e) / 2;

        // left
        mergeSort(nums, s, mid, cnt);
        // right
        mergeSort(nums, mid + 1, e, cnt);

        merge(nums, s, mid, e, cnt);
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        mergeSort(nums, 0, n-1, cnt);

        return cnt;
    }
};

// T.C. : O(N*log(N))
// S.C. : O(1)