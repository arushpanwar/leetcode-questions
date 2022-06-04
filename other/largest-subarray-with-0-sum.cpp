class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<int,int> m;
        int ans=0,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==0){
                ans=i+1;
            }else{
                if(m.count(sum)){
                    ans=max(ans,i-m[sum]);
                }else{
                    m[sum]=i;
                }
            }
        }
        return ans;
    }
};
