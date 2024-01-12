class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        
        for(int i=0;i<s.size();i++){
            s[i] = tolower(s[i]);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                if(i<s.size()/2){
                    cnt1++;
                }
                else{
                    cnt1--;
                }
            }
        }
        return cnt1==0;
    }
};