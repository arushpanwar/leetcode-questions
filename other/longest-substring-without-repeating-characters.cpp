class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0,l=0,r=0;
        unordered_map<char,int> m;
        while(r<s.size()){
            if(m.count(s[r]))l=max(m[s[r]]+1,l);
            len=max(len,r-l+1);
            m[s[r]]=r;
            r++;
        }
        return len;
    }
};
