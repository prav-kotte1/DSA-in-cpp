class Solution {
private:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i < 0 || j<0 || matrix[i][j]) return 0;
        else if (i==0 && j==0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = f(i-1, j, matrix, dp);
        int left = f(i, j-1, matrix, dp);
        return dp[i][j] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, matrix, dp);
    }
};