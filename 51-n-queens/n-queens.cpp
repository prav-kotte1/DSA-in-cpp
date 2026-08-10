class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<int> cols(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);
        vector<string> board(n, string(n, '.'));

        dfs(n, 0, cols, diag1, diag2, board, ans);

        return ans;
    }

private:
    void dfs(int n,
             int i,
             vector<int>& cols,
             vector<int>& diag1,
             vector<int>& diag2,
             vector<string>& board,
             vector<vector<string>>& ans) {

        if (i == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; ++j) {

            if (cols[j] ||
                diag1[i + j] ||
                diag2[j - i + n - 1]) {
                continue;
            }

            // Place queen
            board[i][j] = 'Q';
            cols[j] = true;
            diag1[i + j] = true;
            diag2[j - i + n - 1] = true;

            // Recursive call
            dfs(n, i + 1, cols, diag1, diag2, board, ans);

            // Backtrack
            board[i][j] = '.';
            cols[j] = false;
            diag1[i + j] = false;
            diag2[j - i + n - 1] = false;
        }
    }
};