class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i=k-1;i<s.size();i++){
            string str="";
            for(int j=i-k+1;j<=i;j++){
                str.push_back(s[j]);
            }
            st.insert(str);
        }
        return st.size()==pow(2,k);
    }
};
