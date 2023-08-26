class Solution {
public:
    int recur(int i, int last, vector<vector<int>>& pairs, int dp[][2005]) {
        if (i >= pairs.size()) return 0;

        if (dp[i][last + 1001] != -1) return dp[i][last + 1001];
        int x = recur(i + 1, last, pairs, dp);
        int y = 0;
        if (pairs[i][0] > last) {
            y = 1 + recur(i + 1, pairs[i][1], pairs, dp);
        }

        return dp[i][last + 1001] = max(x, y);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int dp[pairs.size() + 1][2005];
        for (int i = 0; i <= pairs.size(); i++) {
            for (int j = 0; j < 2005; j++) {
                dp[i][j] = -1;
            }
        }

        return recur(0, -1001, pairs, dp);
    }
};
