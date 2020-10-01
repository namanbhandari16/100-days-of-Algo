// Leetcode Problem link - https://leetcode.com/problems/count-of-range-sum/

// Problem Statement:
// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i = j), inclusive.
// 
// Example:
// Input: nums = [-2,5,-1], lower = -2, upper = 2,
// Output: 3 
// Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.

class Solution {
public:
    vector<int> bit;
    
    void update(int i){
        for(;i<bit.size();i+=(i&-i)){
            bit[i]+=1;
        }
    }
    
    int sum(int i){
        int sum = 0;
        for(;i>0;i-=(i&-i)){
            sum+=bit[i];
        }
        return sum;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> pre(n+1,0);
        
        bit.resize(n+2, 0);
        
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i]+nums[i];
        }
        vector<long long> temp(pre);
        sort(temp.begin(), temp.end());
        
        long long ans=0;
        for(int i=0;i<=n;i++){
            long long val = pre[i];
            int l = lower_bound(temp.begin(), temp.end(), val-upper) - temp.begin();
            int r = upper_bound(temp.begin(), temp.end(), val-lower) - temp.begin();
            ans+= sum(r)-sum(l);
            update(upper_bound(temp.begin(), temp.end(), val)-temp.begin());
        }
        return ans;
    }
};
