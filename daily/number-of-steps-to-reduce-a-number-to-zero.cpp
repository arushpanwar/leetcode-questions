class Solution {
public:
    int numberOfSteps(int n) {
        int count=0;
        while(n){
            count++;
            if(n&1)n-=1;
            else n/=2;
        }
        return count;
    }
};
