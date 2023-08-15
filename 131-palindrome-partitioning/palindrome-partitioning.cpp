class Solution {
public:
    vector<vector<string>>st;
    bool isPalindrome(std::string s) {
    return s == std::string(s.rbegin(), s.rend());
}
    void recur(int l,int n,string s,vector<string>&stt){
        if(l==n){
            st.push_back(stt);
        }
        string temp="";
        for(int i=l;i<n;i++){
            temp+=s[i];

            if(isPalindrome(temp)){
                stt.push_back(temp);
                recur(i+1,n,s,stt);
                stt.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string>stt;
        int n=s.size();
        recur(0,n,s,stt);
        return st;
    }
};