class Solution {
public:
    bool issafe(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    v[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            int x = p.first.first;
            int y = p.first.second;
            int z = p.second;
            q.pop();

            if (issafe(x - 1, y, n, m) && v[x - 1][y] > z + 1) {
                q.push({{x - 1, y}, z + 1});
                v[x - 1][y] = z + 1;
            }
            if (issafe(x + 1, y, n, m) && v[x + 1][y] > z + 1) {
                q.push({{x + 1, y}, z + 1});
                v[x + 1][y] = z + 1;
            }
            if (issafe(x, y + 1, n, m) && v[x][y + 1] > z + 1) {
                q.push({{x, y + 1}, z + 1});
                v[x][y + 1] = z + 1;
            }
            if (issafe(x, y - 1, n, m) && v[x][y - 1] > z + 1) {
                q.push({{x, y - 1}, z + 1});
                v[x][y - 1] = z + 1;
            }
        }

        return v;
    }
};
