class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int lastOne = -1;
        int c=0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                c++;
            }
        }

        
       string temp="";
        for(int i=0;i<n;i++){
            temp+="0";
        }
        for(int i=0;i<c-1;i++){
            temp[i]='1';
        }
        temp[n-1]='1';
        
        

        return temp;
    }
};
