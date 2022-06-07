class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        vector<int> left(n,0),right(n,0);
        for(int i=1;i<n;i++)left[i]=max(left[i-1],height[i-1]);
        for(int i=n-2;i>=0;i--)right[i]=max(right[i+1],height[i+1]);
        for(int i=0;i<n;i++)left[i]=min(left[i],right[i]);
        for(int i=0;i<n;i++)ans+=max(0,left[i]-height[i]);
        return ans;
    }
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,lmax=0,rmax=0,res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lmax)lmax=height[left++];
                else res+=lmax-height[left++];
            }else{
                if(height[right]>=rmax)rmax=height[right--];
                else res+=rmax-height[right--];
            }
        }
        return res;
    }
};
