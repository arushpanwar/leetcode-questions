class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        dp[m][n]=1;
        for(int i=m;i>0;i--){
            for(int j=n;j>0;j--){
                dp[i-1][j]+=dp[i][j];
                dp[i][j-1]+=dp[i][j];
            }
        }
        return dp[1][1];
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};
