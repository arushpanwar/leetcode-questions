class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<pair<int,int>>& v,int m,int n,int size){
        if(size==0)return 0;
        if(dp[size-1][m][n]!=-1)return dp[size-1][m][n];
        if(v[size-1].first<=m&&v[size-1].second<=n)return dp[size-1][m][n]=max(1+solve(v,m-v[size-1].first,n-v[size-1].second,size-1),solve(v,m,n,size-1));
        return dp[size-1][m][n]=solve(v,m,n,size-1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+2, vector<vector<int>>(m+2, vector<int>(n+2, -1)));
        vector<pair<int, int>> v;
        for(string x : strs){
            int cnt = count(x.begin(), x.end(), '0');
            v.push_back({cnt, x.size()-cnt});
        }
        return solve(v,m,n,strs.size());
    }
};
