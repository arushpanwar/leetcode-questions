class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long int res=1;
        for(int i=1;i<=rowIndex;i++){
            res*=(rowIndex-i+1);
            res/=(i);
            ans.push_back((int)res);
        }
        return ans;
    }
};
