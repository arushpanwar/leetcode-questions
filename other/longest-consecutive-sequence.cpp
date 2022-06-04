class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto i:nums)s.insert(i);
        int mx=0;
        int count=0;
        for(auto ele:nums){
            int prev=ele-1;
            if(s.find(prev)==s.end()){
                int next=ele+1;
                count=1;
                while(s.find(next)!=s.end()){
                    next++;
                    count++;
                }
                mx=max(mx,count);
            }
        }
        return mx;
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i]-1))m[nums[i]]=m[nums[i]-1]+1;
            else m[nums[i]]=1;
        }
        int ans=INT_MIN;
        for(auto x:m)ans=max(ans,x.second);
        return ans;
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set <int> s;
        int ans=INT_MIN;
        for(auto x:nums)s.insert(x);
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i]-1)==0){
                int x=nums[i],cnt=0;
                while(s.count(x)){
                    cnt++;
                    x++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
