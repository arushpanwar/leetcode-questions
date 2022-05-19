class Solution {
public:
    int n,m;
    bool isPossible(int x,int y,int a,int b,vector<vector<int>>& matrix){
        return x>=0&&x<n&&y>=0&&y<m&&matrix[a][b]<matrix[x][y];
    }
    int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int x,int y){
        if(dp[x][y])return dp[x][y];
        int ans=0;
        if(isPossible(x-1,y,x,y,matrix))ans=max(ans,solve(matrix,dp,x-1,y));
        if(isPossible(x+1,y,x,y,matrix))ans=max(ans,solve(matrix,dp,x+1,y));
        if(isPossible(x,y+1,x,y,matrix))ans=max(ans,solve(matrix,dp,x,y+1));
        if(isPossible(x,y-1,x,y,matrix))ans=max(ans,solve(matrix,dp,x,y-1));
        return dp[x][y]=ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        int sol=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j])sol=max(sol,dp[i][j]);
                else sol=max(sol,solve(matrix,dp,i,j));
            }
        }
        return sol;
    }
};
