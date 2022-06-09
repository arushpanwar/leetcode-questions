class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int size){
        vector<int> temp;
        ans.push_back(temp);
        temp.push_back(nums[0]);
        ans.push_back(temp);
        for(int k=1;k<size;k++){
            int n=ans.size();
            for(int j=0;j<n;j++){
                temp=ans[j];
                temp.push_back(nums[k]);
                ans.push_back(temp);
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,nums.size());
        return ans;
    }
};
