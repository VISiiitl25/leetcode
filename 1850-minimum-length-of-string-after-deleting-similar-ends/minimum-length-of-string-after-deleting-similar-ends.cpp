class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int l=0,h=n-1;
        while(l<h){
            if(s[l]!=s[h]){
                break;
            }
            int c=s[l];
            while(s[l]==c){
                l++;
            }
        if(h<l)return 0;
            while(s[h]==c){
                h--;
            }
        }
        return h-l+1;
       
    }
};