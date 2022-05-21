class Solution {
public:
    int find(int v,vector<int>& arr){
        if(arr[v]==-1)return v;
        return find(arr[v],arr);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> arr(n+1,-1);
        vector<int> ans;
        for(auto p:edges){
            int from=find(p[0],arr);
            int to=find(p[1],arr);
            if(from==to)return p;
            from=find(from,arr);
            to=find(to,arr);
            arr[from]=to;
        }
        return ans;
    }
};
