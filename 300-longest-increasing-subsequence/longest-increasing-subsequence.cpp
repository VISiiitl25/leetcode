class Solution {
public:
       int solve(int cur, int prev, vector<int>& nums, int n, vector<vector<int>> & dp){
        if(cur==n){return 0;}
        if(dp[cur][prev+1]!=-1){return dp[cur][prev+1];}
        int len = 0 + solve(cur+1,prev,nums,n,dp);
        if(prev==-1 || nums[cur]>nums[prev]){
            len = max(len,1+ solve(cur+1,cur,nums,n,dp));
        }
        return dp[cur][prev+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,nums.size(),dp);
    
    }
};
