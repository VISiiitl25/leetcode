class Solution {
public:
    int recur(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& memo) {
       
        if (i == grid.size() || j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) {
            return 0;
        }

        if (memo[i][j1][j2] != -1) {
            return memo[i][j1][j2];
        }

        if (i == grid.size() - 1) {
            return grid[i][j1] + (j1 != j2 ? grid[i][j2] : 0);
        }

        int cherries = grid[i][j1] + (j1 != j2 ? grid[i][j2] : 0);
        int maxa = 0;

        for (int k = -1; k <= 1; k++) {
            for (int u = -1; u <= 1; u++) {
                int newh = recur(i + 1, j1 + k, j2 + u, grid, memo);
                maxa = max(maxa, cherries + newh);
            }
        }

        memo[i][j1][j2] = maxa;
        return maxa;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return recur(0, 0, n - 1, grid, memo);
    }
};
