class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int target,int row){
        for(int i=0;i<matrix[row].size();i++){
            if(matrix[row][i]==target)return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(i+1<n&&matrix[i+1][0]>target)return searchRow(matrix,target,i);
            if(i+1==n)return searchRow(matrix,target,i);
        }
        return false;
    }
      //other approach
      bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]>target)j--;
            else i++;
        }
        return false;
    }
  //binary search
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),low=0,high=(n*m)-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid/m][mid%m]==target)return true;
            if(matrix[mid/m][mid%m]<target)low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};
