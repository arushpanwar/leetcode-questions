class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return;
        int ptr1=-1,ptr2;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ptr1=i;
                break;
            }
        }
        if(ptr1==-1)return;
        ptr2=ptr1+1;
        while(ptr2<n){
            // cout<<ptr1<<" "<<ptr2<<endl;
            if(nums[ptr2]==0){
                ptr2++;
            }else{
                // cout<<ptr1<<" "<<ptr2<<endl;
                swap(nums[ptr1],nums[ptr2]);
                // cout<<ptr1<<" "<<ptr2<<endl;
                ptr1++;
                ptr2++;
            }
        }
      
      
      
      //second approach
        for (int i=0, p = 0;i<nums.size();i++)
		    if (nums[i] != 0)
			    swap(nums[p++], nums[i]);
    }
};
