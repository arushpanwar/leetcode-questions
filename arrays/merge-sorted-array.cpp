class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1=m-1,ptr2=n-1;
        for(int i=n+m-1;i>=0;i--){
            if(ptr1!=-1&&ptr2!=-1){
                if(nums1[ptr1]>=nums2[ptr2])nums1[i]=nums1[ptr1--];
                else nums1[i]=nums2[ptr2--];
            }else if(ptr1==-1){
                nums1[i]=nums2[ptr2--];
            }else{
                nums1[i]=nums1[ptr1--];
            }
        }
    }
};
