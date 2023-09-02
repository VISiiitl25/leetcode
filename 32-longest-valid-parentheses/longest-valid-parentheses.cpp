class Solution {
public:
    int f[100005]={};
    int longestValidParentheses(string s) {
        stack<int>st;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                int c=st.top();st.pop();

                f[i+1]=f[c]+i+1-c;
                maxi=max(maxi,f[i+1]);
            }}
        }
        return maxi;
    }
};