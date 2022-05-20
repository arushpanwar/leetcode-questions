class Solution {
public:
    int n,m;
    bool isPossible(vector<vector<int>>& obstacleGrid,int x,int y){
        return x<n&&y<m&&obstacleGrid[x][y]==0;
    }
    int solve(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int x,int y){
        if(x==n-1&&y==m-1)return 1;
        if(dp[x][y])return dp[x][y];
        int ans=0;
        if(isPossible(obstacleGrid,x+1,y))ans+=solve(obstacleGrid,dp,x+1,y);
        if(isPossible(obstacleGrid,x,y+1))ans+=solve(obstacleGrid,dp,x,y+1);
        return dp[x][y]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size(),m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<int>> dp(n,vector<int> (m,0));
        return solve(obstacleGrid,dp,0,0);
    }
};
