class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>>graph;
    vector<int> firstTime,minTime,visited;
    int time=1;
     
    void dfs(int n,int parent){
        firstTime[n]=minTime[n]=time++;
        visited[n]=true;
        for(auto& child : graph[n]){
            if(child==parent)continue;
            if(!visited[child])dfs(child,n);
            minTime[n]=min(minTime[child],minTime[n]);
            if(firstTime[n]<minTime[child])ans.push_back({n,child});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        firstTime.resize(n), minTime.resize(n), visited.resize(n), graph.resize(n);
        for(auto& edge:connections){
            int nodeA = edge[0], nodeB = edge[1];
			graph[nodeA].push_back(nodeB);
			graph[nodeB].push_back(nodeA);
        }
        dfs(0,-1);
        return ans;
    }
};
