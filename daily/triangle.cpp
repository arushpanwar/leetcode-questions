class Solution {
public:
    int helper(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>& dp){
        if(j==n-1)return triangle[j][i];
        if(dp[j][i]!=-1)return dp[j][i];
        int ans=INT_MAX;
        ans=min(ans,triangle[j][i]+helper(triangle,i,j+1,n,dp));
        ans=min(ans,triangle[j][i]+helper(triangle,i+1,j+1,n,dp));
        return dp[j][i]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(triangle,0,0,n,dp);
    }
   int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int>next(n);
		for(int i = n-1; i >= 0; i--) {
			vector<int>curr(n);
			for(int j = i; j >= 0; j--) {
				if(i == n-1)
					curr[j] = triangle[i][j];
				else {
					int up = triangle[i][j] + next[j];
					int up_left = triangle[i][j] + next[j+1];
					curr[j] = min(up, up_left);
				}
			}
			next = curr;
		}
		return next[0];
	}
};

