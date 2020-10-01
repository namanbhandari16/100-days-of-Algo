// Leetcode Problem link - https://leetcode.com/problems/range-sum-query-mutable/

// Problem Statement:
// Given an integer array nums, find the sum of the elements between indices i and j (i = j), inclusive.
// The update(i, val) function modifies nums by updating the element at index i to val.
// Example:
// Given nums = [1, 3, 5]
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8

class NumArray {
    vector<int> bit;
    vector<int> nums;
    
public:
    NumArray(vector<int>& nums) {
        this->nums=nums;
        int n = nums.size();
        bit.resize(n+2, 0);
        for(int i=1;i<=n;i++)
            bit[i]=bit[i-1]+nums[i-1];
        for(int i=n;i>0;i--)
            bit[i]-=bit[i-(i&-i)];
    }
    
    void bitupdate(int i, int val){
        for(;i<bit.size();i+=(i&-i))
            bit[i]+=val;
    }
    
    int bitsum(int i){
        int sum=0;
        for(;i>0;i-=(i&-i))
            sum+=bit[i];
        return sum;
    }
    
    void update(int i, int val) {
        bitupdate(i+1, val-nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        if(i>j) swap(i, j);
        return bitsum(j+1)-bitsum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
