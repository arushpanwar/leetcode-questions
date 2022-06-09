vector<int> ans;
    void solve(vector<int>& nums,int size){
        ans.push_back(0);
        ans.push_back(nums[0]);
        for(int i=1;i<size;i++){
            int n=ans.size();
            for(int j=0;j<n;j++){
                ans.push_back(nums[i]+ans[j]);
            }
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        solve(arr,N);
        return ans;
    }

vector<int> ans;
    void helper(vector<int> arr,int i,int N,int sum){
        if(i==N){
            ans.push_back(sum);
            return;
        }
        helper(arr,i+1,N,sum+arr[i]);
        helper(arr,i+1,N,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        helper(arr,0,N,0);
        return ans;
    }
