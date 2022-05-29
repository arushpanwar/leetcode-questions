class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int>& dp) {
        if(amount==0)return 0;
        if(amount<0||coins.size()==0)return -1;
        if(dp[amount]!=-2)return dp[amount];
        sort(coins.begin(),coins.end());
        if(coins[0]>amount)return -1;
        int ans=INT_MAX;
        for(auto coin: coins)
            if(solve(coins,amount-coin,dp)!=-1)ans=min(ans,solve(coins,amount-coin,dp));
        if(ans==INT_MAX)return dp[amount]=-1;
        return dp[amount]=1+ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);
        return solve(coins,amount,dp);
    }
};


