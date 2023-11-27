#include <vector>

class Solution {
public:
    bool isvalid(int x, int y) {
        return (x >= 0 && y >= 0 && x < 4 && y < 3 && !(x == 3 && y == 0) && !(x == 3 && y == 2));
    }

    int recur(int x, int y, int n, vector<vector<vector<int>>>& dp) {
        if (n == 1)
            return 1;
        
        if (dp[x][y][n] != -1)
            return dp[x][y][n];
        
        int a[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int b[8] = {1, -1, 2, -2, 2, -2, 1, -1};

        int ans = 0;
        for (int i = 0; i < 8; i++) {
            int x1 = x + a[i], y1 = y + b[i];
            
            if (isvalid(x1, y1)) {
                ans += recur(x1, y1, n - 1, dp);
                ans %= 1000000007;
            }
        }
        
        return dp[x][y][n] = ans;
    }
    
    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        int ans = 0;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(i == 3 && j == 0) && !(i == 3 && j == 2)) {
                    ans += recur(i, j, n, dp);
                    ans %= 1000000007;
                }
            }
        }
        
        return ans;
    }
};
