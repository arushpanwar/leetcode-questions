class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        int duprow=row,dupcol=col;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=duprow;col=dupcol;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q')return false;
            row--;col--;
        }
        row=duprow;col=dupcol;
        while(row<n&&col>=0){
            if(board[row][col]=='Q')return false;
            row++;col--;
        }
        return true;
    }
    void solve(int& ans,int col,vector<string>& board,int n){
        if(col==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]='Q';
                solve(ans,col+1,board,n);
                board[i][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)board[i]=s;
        solve(ans,0,board,n);
        return ans;
    }
};
