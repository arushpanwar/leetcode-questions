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
};
