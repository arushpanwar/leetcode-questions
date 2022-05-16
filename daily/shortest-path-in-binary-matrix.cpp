class Solution {
public:
    bool valid(vector<vector<int>>& grid,int i,int j,int n,vector<vector<bool>>& visited){
        return (i>=0&&i<n&&j>=0&&j<n&&visited[i][j]==false&&grid[i][j]==0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        queue <pair<int,int>> q;
        int ans=0;
        int nodesPushed;
        if(grid[0][0]==0){
            visited[0][0]=true;
            q.push({0,0});
        }
        while(!q.empty()){
            nodesPushed=q.size();
            ans++;
            for(int cnt=0;cnt<nodesPushed;cnt++){
                pair<int,int> frontNode=q.front();
                q.pop();
                int i=frontNode.first,j=frontNode.second;
                if(i==n-1&&j==n-1)return ans;
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        if(valid(grid,k,l,n,visited)){
                            q.push({k,l});
                            visited[k][l]=true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
