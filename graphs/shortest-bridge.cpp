class Solution {
public:
    vector<pair<int,int>> v1,v2;
    int n;
    bool isPossible(int i,int j,vector<vector<int>>& grid){
        return i>=0&&i<n&&j>=0&&j<n&&grid[i][j]==1;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,vector<pair<int,int>>& v){
        v.push_back({i,j});
        visited[i][j]=1;
        if(isPossible(i+1,j,grid)&&visited[i+1][j]==0)dfs(grid,visited,i+1,j,v);
        if(isPossible(i-1,j,grid)&&visited[i-1][j]==0)dfs(grid,visited,i-1,j,v);
        if(isPossible(i,j+1,grid)&&visited[i][j+1]==0)dfs(grid,visited,i,j+1,v);
        if(isPossible(i,j-1,grid)&&visited[i][j-1]==0)dfs(grid,visited,i,j-1,v);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>> visited(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    if(v1.size()==0)dfs(grid,visited,i,j,v1);
                    else dfs(grid,visited,i,j,v2);
                }
            }
        }
        int ans=INT_MAX;
        for(auto i:v1){
            for(auto j:v2){
                ans=min(ans,abs(i.first-j.first)+abs(i.second-j.second));
            }
        }
        return ans-1;
    }
};
