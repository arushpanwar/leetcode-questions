class Solution {
public:
    int numTrees(int n) {
        if(n==0||n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 5;
        int total=0;
        for(int i=0;i<n;i++){
            int left=numTrees(i);
            int right=numTrees(n-i-1);
            total+=left*right;
        }
        return total;
    }
};


//Memoization code 100% faster
int totalBst(int n,vector<int>& dp){
        if(n==0||n==1)return dp[n]=1;
        if(n==2)return dp[n]=2;
        if(dp[n]!=0)return dp[n];
        int total=0;
        for(int i=0;i<n;i++){
            total+=totalBst(i,dp)*totalBst(n-i-1,dp);
        }
        return dp[n]=total;
    }
    
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        return totalBst(n,dp);
    }


//Bottom Up DP
int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
