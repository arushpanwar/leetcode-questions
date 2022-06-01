class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum=0,ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum=max(arr[i],sum+arr[i]);
            ans=max(ans,sum);
        }
        return ans;
    }
};
