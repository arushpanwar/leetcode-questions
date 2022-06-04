class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int duprow=row,dupcol=col;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n&&col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n,vector<int>& leftRow,vector<int>& lowerDaigonal,vector<int>& upperDaigonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0&&lowerDaigonal[row+col]==0&&upperDaigonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDaigonal[row+col]=1;
                upperDaigonal[n-1+col-row]=1;
                solve(col+1,board,ans,n,leftRow,lowerDaigonal,upperDaigonal);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDaigonal[row+col]=0;
                upperDaigonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        vector<int> leftRow(n,0),lowerDaigonal(2*n-1,0),upperDaigonal(2*n-1,0);
        solve(0,board,ans,n,leftRow,lowerDaigonal,upperDaigonal);
        return ans;
    }
};
