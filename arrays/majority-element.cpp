class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int sum=INT_MIN,ans;
        for(auto x:m){
            if(x.second>sum){
                sum=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
    int majorityElement(vector<int>& nums) {
        int count=1,maj=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maj){
                count++;
            }else{
                count--;
                if(count==0){
                    maj=nums[i];
                    count=1;
                }
            }
        }
        return maj;
    }
};
