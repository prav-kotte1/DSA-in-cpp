class Solution {
    int fnc(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0) return 1; //base case
        if(i<0 || j<0) return 0; //out of bounds case
        if(dp[i][j] != -1) return dp[i][j]; //already computed case
        int down = fnc(i-1, j, dp);
        int right = fnc(i, j-1, dp);
        return dp[i][j] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return fnc(m-1, n-1, dp);
    }
};