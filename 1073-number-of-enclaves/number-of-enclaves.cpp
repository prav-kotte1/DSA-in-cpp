class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m) return;
        if(grid[row][col] != 1) return;
        grid[row][col] = 0;

        dfs(row+1, col, grid);
        dfs(row-1, col, grid);
        dfs(row, col+1, grid);
        dfs(row, col-1, grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1)
                dfs(i, 0, grid);
            if(grid[i][m-1] == 1)
                dfs(i, m-1, grid);
        }

        for(int j=0; j<m; j++){
            if(grid[0][j] == 1)
                dfs(0, j, grid);
            if(grid[n-1][j] == 1)
                dfs(n-1, j, grid);
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};