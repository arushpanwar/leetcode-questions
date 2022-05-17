class Solution {
public:
    int numTrees(int n) {
        if(n==0||n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 5;
        int total=0;
        for(int i=0;i<n;i++){
            int left=numTrees(i);
            int right=numTrees(n-i-1);
            total+=left*right;
        }
        return total;
    }
};
