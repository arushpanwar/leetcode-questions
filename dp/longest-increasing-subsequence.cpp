class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int index,int prevIndex){
        if(index==nums.size())return 0;
        if(dp[index+1][prevIndex+1]!=-1)return dp[index+1][prevIndex+1];
        if(prevIndex==-1||nums[index]>nums[prevIndex])
            return dp[index+1][prevIndex+1]=max(1+helper(nums,index+1,index),helper(nums,index+1,prevIndex));
        return dp[index+1][prevIndex+1]=helper(nums,index+1,prevIndex);
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1,vector<int> (nums.size()+1,-1));
        return helper(nums,0,-1);
    }
};
