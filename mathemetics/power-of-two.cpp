class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n){
            if(n&1){
                if(n>>1==0)return true;
                else return false;
            }
            n>>=1;
        }
        return false;
    }
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int ans = n&(n-1);
        return (ans == 0)?true : false;
    }
};
