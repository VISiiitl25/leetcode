class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count=0;
        for(int i=0;i<26;i++){
            char c='a'+i;
            int l=s.find(c);
            int r=s.rfind(c);
            if(l!=-1&&r!=-1&& l<r){
            count+=(set<char>(s.begin()+l+1,s.begin()+r).size());
            }
        }
        return count;
    }
};