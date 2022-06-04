class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        if(n==0)return ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=target-nums[i]-nums[j];
                    if(sum==nums[left]+nums[right]){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        while(left<right&&nums[left]==nums[left+1])left++;
                        while(left<right&&nums[right]==nums[right-1])right--;
                        left++;
                        right--;
                    }else if(sum>nums[left]+nums[right])left++;
                    else right--;
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};
