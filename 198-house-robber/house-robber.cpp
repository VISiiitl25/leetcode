class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0) {
            return nums[0];
        }
        if (i == 1) {
            return max(nums[0], nums[1]);
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int x = helper(i - 1, nums, dp);
        int y = helper(i - 2, nums, dp) + nums[i];
        dp[i] = max(x, y);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, -1);
        return helper(n - 1, nums, dp);
    }
};
