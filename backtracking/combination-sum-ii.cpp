class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,vector<int>& candidates, int target,vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0)return;
        for(int i=ind;i<candidates.size();i++){
            if(i!=ind&&candidates[i]==candidates[i-1])continue;
            temp.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,temp);
        return ans;
    }
};
