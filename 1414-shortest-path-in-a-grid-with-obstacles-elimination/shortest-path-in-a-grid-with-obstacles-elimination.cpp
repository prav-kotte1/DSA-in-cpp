class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int n = grid.size(); //rows
        int m = grid[0].size(); //cols

        if(m==1 && n==1) return 0;
        if(k >= m+n -2) return m+n-2;

        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});
        vis[0][0][k] = true;

        int steps = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto[x, y, rem] = q.front();
                q.pop();
                if(x == n-1 && y == m-1) return steps;
                for(int i=0; i<4; i++){
                    int nr = x + dr[i];
                    int nc = y + dc[i];

                    if(nc < 0 || nr < 0 || nr >= n || nc >= m) continue;
                    int nrem = rem - grid[nr][nc];

                    if(nrem < 0) continue;
                    if(vis[nr][nc][nrem]) continue;
                    vis[nr][nc][nrem] = true;
                    q.push({nr, nc, nrem});
                }
            }
            steps++;
        }
        return -1;
    }
};