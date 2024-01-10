class Solution {
public:
    int recur(string &s, string &t, int i, int j, vector<vector<int>> &memo) {
        if (i == s.size() && j == t.size()) {
            return 0; 
        }
        if (i == s.size()) {
            return t.size() - j; 
        }
        if (j == t.size()) {
            return s.size() - i; 
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int x = 1 + recur(s, t, i, j + 1, memo);    
        int y = 1 + recur(s, t, i + 1, j, memo);    
        int z = (s[i] == t[j]) ? recur(s, t, i + 1, j + 1, memo) : 1 + recur(s, t, i + 1, j + 1, memo); 

        memo[i][j] = min({x, y, z});
        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return recur(word1, word2, 0, 0, memo);
    }
};
