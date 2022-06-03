class NumMatrix {
public:
    vector<vector<int>> m,prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            vector<int> temp;
            for(int j=0;j<matrix[0].size();j++){
                temp.push_back(matrix[i][j]);
            }
            m.push_back(temp);
        }
        prefix=m;
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                prefix[i][j]+=prefix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            sum+=prefix[i][col2]-prefix[i][col1]+m[i][col1];
        }
        return sum;
    }
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        prefix=vector<vector<int>> (n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;col1++;row2++;col2++;
        return (prefix[row2][col2]-prefix[row2][col1-1]-prefix[row1-1][col2]+prefix[row1-1][col1-1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
