class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int recur(int i, int n, const string& s, vector<int>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int mini = INT_MAX;

        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                int cost = 1 + recur(j + 1, n, s, dp);
                mini = min(mini, cost);
            }
        }

        dp[i] = mini;
        return mini;
    }

    int minCut(const string& s) {
        int n = s.length();
        vector<int> dp(n, -1);

        return recur(0, n, s, dp) - 1;
    }
};
