class Solution {
public:
void printVector(const vector<vector<int>> &vec) {
    for (const auto &row : vec) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n=str1.size(),m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int l=n,h=m;
        string ans="";
        while(l&&h){
            if(str1[l-1]==str2[h-1]){
                ans=str1[l-1]+ans;l--;h--;
            }
            else if(dp[l-1][h]>dp[l][h-1]){
                ans=str1[l-1]+ans;l--;
            }
            else{
                ans=str2[h-1]+ans;h--;
            }
        }
        while(l){
            ans=str1[l-1]+ans;l--;
        }
         while(h){
            ans=str2[h-1]+ans;h--;
        }
        
        return ans;}
};