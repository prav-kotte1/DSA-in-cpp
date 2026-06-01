class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& img, int color, int newcolor){
        int n = img.size();
        int m = img[0].size();

        img[row][col] = newcolor;

        int dr[] ={-1, 0, 1, 0};
        int dc[] ={0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               img[nr][nc] == color){
                dfs(nr, nc, img, color, newcolor);
               }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int col = image[sr][sc];

        if(col == newcolor)
            return image;

        dfs(sr, sc, image, col, newcolor);
        return image;
    }
};