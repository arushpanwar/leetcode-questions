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


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i&&dp[i-coins[j]]!=-1){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
            if(dp[i]==INT_MAX-1)dp[i]=-1;
        }
        return dp[amount];
    }
};
