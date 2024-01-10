class Solution {
public:
    unordered_map<string, bool> memo;

    bool dfs(int i, int j, const string& s, const string& p) {
        if (j == p.size()) {
            return i == s.size();
        }

        string key = to_string(i) + "," + to_string(j);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        bool result = false;
        if (i < s.size() && (s[i] == p[j] || p[j] == '?')) {
            result = dfs(i + 1, j + 1, s, p);
        } else if (p[j] == '*') {
            result = dfs(i, j + 1, s, p) || (i < s.size() && dfs(i + 1, j, s, p));
        }

        memo[key] = result;
        return result;
    }

    bool isMatch(string s, string p) {
        return dfs(0, 0, s, p);
    }
};