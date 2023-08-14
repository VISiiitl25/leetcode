class Solution {
public:
    vector<vector<string>> ans;
    
    bool issafe(vector<vector<char>>& q, int row, int col, int n) {
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0) {
        if (q[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0) {
        if (q[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0) {
        if (q[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

    
    void recur(vector<vector<char>>& q, int col, int n) {
        if (col == n) {
            vector<string> solution;
            for (int i = 0; i < n; i++) {
                solution.push_back(string(q[i].begin(), q[i].end()));
            }
            ans.push_back(solution);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (issafe(q, i, col, n)) {
                q[i][col] = 'Q';
                recur(q, col + 1, n);
                q[i][col] = '.';
            }
            
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> q(n, vector<char>(n, '.'));
        recur(q, 0, n);
        return ans;
    }
};
