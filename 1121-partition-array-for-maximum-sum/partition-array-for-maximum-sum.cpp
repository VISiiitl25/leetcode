class Solution {
public:
    int maxa; 
    int dp[505][505];

    int recur(int i, int len,int h, vector<int>& arr, int k) {
        if (i >= arr.size()) return 0;
        if(dp[i][len]!=-1)return dp[i][len];
        if (len+1 <= k) {
            h = max(h, arr[i]);
           
            int x = recur(i + 1, len + 1,h, arr, k);
            
            int y = (len+1) * h + recur(i + 1, 0,0, arr, k);
            return dp[i][len]=max(x, y);
        }
        return dp[i][len]=0;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        maxa = 0;
        memset(dp,-1,sizeof(dp));
        return recur(0, 0,0, arr, k);
    }
};
