class Solution {
public:
    void setZeroRow(vector<vector<int>>& matrix,int x){
        for(int i=0;i<matrix[0].size();i++){
            matrix[x][i]=0;
        }
    }
    void setZeroColoumn(vector<vector<int>>& matrix,int x){
        for(int i=0;i<matrix.size();i++){
            matrix[i][x]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> x,y;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        for(int i=0;i<x.size();i++)setZeroRow(matrix,x[i]);
        for(int i=0;i<x.size();i++)setZeroColoumn(matrix,y[i]);
    }
};
