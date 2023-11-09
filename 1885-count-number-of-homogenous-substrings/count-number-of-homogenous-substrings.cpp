class Solution {
public:
    int m=pow(10,9)+7;
    int countHomogenous(string s) {
        int n=s.size();

        int i=0;
        int ans=0;
        while(i<n){
            char c=s[i];
            long long count=0;
            int j=i;
            while(s[i]==s[j]){
                count++;
                j++;
            }
            i=j;
            long long z=((count%m)*((count+1)%m))%m;

            ans+=(z/2);
        }
        return ans;
    }
};