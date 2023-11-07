class Solution {
public:
    vector<vector<long long>> dp; 
    
    long long recur(vector<int>& nums, bool state, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i][state] != -1) {
            return dp[i][state];
        }
        long long x = 0, y = 0;
        //take
        if (!state) {
            x = max(nums[i] + recur(nums, 1, i + 1), recur(nums, 0, i + 1));
            dp[i][state] = x;
        } else {
            y = max(-nums[i] + recur(nums, 0, i + 1), recur(nums, 1, i + 1));
            dp[i][state] = y;
        }
        return dp[i][state];
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<long long>(2, -1));
        return recur(nums, false, 0);
    }
};
