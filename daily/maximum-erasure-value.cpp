class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0,ans=0,sum=0;
        unordered_set<int> s;
        while(r<nums.size()){
            if(s.count(nums[r])){
                while(nums[l]!=nums[r]){
                    sum-=nums[l];
                    s.erase(nums[l]);
                    l++;
                }
                l++;
            }else{
                sum+=nums[r];
                s.insert(nums[r]);
            }
            ans=max(ans,sum);
            r++;
        }
        return ans;
    }
};
