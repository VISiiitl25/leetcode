class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
       
        vector<vector<int>> memo(n, vector<int>(m, -1));
        
        return recur(0, 0, n, m, text1, text2, memo);
    }
    
    int recur(int i, int j, int n, int m, string& text1, string& text2, vector<vector<int>>& memo) {
        if (i >= n || j >= m) {
            return 0;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + recur(i + 1, j + 1, n, m, text1, text2, memo);
        } else {
            memo[i][j] = max(recur(i + 1, j, n, m, text1, text2, memo), recur(i, j + 1, n, m, text1, text2, memo));
        }
        
        return memo[i][j];
    }
};
