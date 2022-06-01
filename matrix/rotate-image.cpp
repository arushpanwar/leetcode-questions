class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        //transpose of matrix
        int n=m.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(m[i][j],m[j][i]);
            }
        }
        //Reverse matrix
        for(int i=0;i<n;i++){
            reverse(m[i].begin(),m[i].end());
        }
    }
};
