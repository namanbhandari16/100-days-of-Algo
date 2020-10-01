// Leetcode Problem link - https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Problem Statement:
// You are given an integer array nums and you have to return a new counts array. The counts array has the property
// where counts[i] is the number of smaller elements to the right of nums[i].
// 
// Example:
// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.

class Solution {
public:
    void update(int idx, vector<int> &ft){
        for(int i=idx;i<ft.size();i+=(i&-i)){
            ft[i]++;
        }
    }
    
    int sum(int idx, vector<int> &ft){
        int ans=0;
        for(int i=idx;i>0;i-=(i&-i)){
            ans += ft[i];
        }
        return ans;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        if(n==0)
            return ans;
        vector<int> ft(20002, 0);
        for(int i=n-1;i>=0;i--){
            ans[i] = sum(nums[i]+10000, ft);
            update(nums[i]+10000+1, ft);
        }
        return ans;
    }
};
