class Solution {
public:
    void helper(vector<int>& nums, set<vector<int>>& s, int x, vector<int>& temp){
        if(x == nums.size()){
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        temp.push_back(nums[x]);
        helper(nums,s,x+1,temp);
        temp.pop_back();
        helper(nums,s,x+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;
        sort(nums.begin() , nums.end());
        helper(nums,s,0,temp);
        for(auto it = s.begin() ; it != s.end() ; it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
