class Solution {
public:
    bool isPallindrome(string s){
        int start=0,end=s.size()-1;
        while(start<=end){
            if(s[start]!=s[end])return false;
            start++;end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            string str="";
            for(int j=i;j<n;j++){
                str.push_back(s[j]);
                if(isPallindrome(str)&&(ans.size()<str.size()))ans=str;
            }
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        //Initialization
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i+1<n)s[i]==s[i+1]?dp[i][i+1]=1:dp[i][i+1]=0;
        }
        //Remaining Code
        pair<int,int> p;
        for(int size=0;size<n;size++){
            for(int i=0,j=size;i<n&&j<n;i++,j++){
                if(dp[i][j]&&(p.second-p.first)<(j-i)){
                    p.first=i;
                    p.second=j;
                }
                if(i-1>=0&&j+1<n){
                    if(dp[i][j]==0)dp[i-1][j+1]=0;
                    else {
                        if(s[i-1]==s[j+1])dp[i-1][j+1]=1;
                        else dp[i-1][j+1]=0;
                    }
                }
            }
        }
        return s.substr(p.first,p.second-p.first+1);
    }
};
