class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n==1){
            return 0;
        }
        vector<long long> prefix1(n, 0), prefix2(n, 0), suffix1(n, 0), suffix2(n, 0);

        

        prefix1[0] = grid[0][0];
        prefix2[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            prefix1[i] = prefix1[i - 1] + grid[0][i];
            prefix2[i] = prefix2[i - 1] + grid[1][i];
        }

        suffix1[n - 1] = grid[0][n - 1];
        suffix2[n - 1] = grid[1][n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix1[i] = suffix1[i + 1] + grid[0][i];
            suffix2[i] = suffix2[i + 1] + grid[1][i];
        }

        long long ans =min(suffix1[1], prefix2[n-2]);
       ;
        for (int i = 1; i < n - 1; ++i) {
            long long x = prefix2[i - 1];
            long long y = suffix1[i + 1];
            ans = min(ans, max(x, y));
        }

        return ans;
    }
};
