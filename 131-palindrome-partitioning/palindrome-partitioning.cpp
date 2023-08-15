class Solution {
public:
    vector<vector<string>>st;
    bool isPalindrome(std::string s) {
    // Convert the string to lowercase
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });

    // Remove non-alphanumeric characters
    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) { return !std::isalnum(c); }), s.end());

    // Compare the string with its reverse
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