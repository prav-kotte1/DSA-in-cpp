class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m)
            return;
        if (grid[row][col] != '1')
            return;
        grid[row][col] = '0';
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            dfs(row + dr[k], col + dc[k], grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};