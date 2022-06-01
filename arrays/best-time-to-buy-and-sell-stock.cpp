class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //O(n)-both time and space solution
        int ans=0,n=prices.size();
        vector<int> arr(n);
        arr[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i]=max(arr[i+1],prices[i]);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,arr[i]-prices[i]);
        }
        return ans;
        
        int ans=0,n=prices.size(),mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]);
            ans=max(ans,prices[i]-mn);
        }
        return ans;
    }
};
