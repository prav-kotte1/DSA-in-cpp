class Solution {
private:
    int f(vector<int>& coins, int rem, vector<int>& dp) {
        // base case
        if (rem == 0)
            return 0;
        if (rem < 0)
            return -1;
        if (dp[rem] != -2)
            return dp[rem];

        int mini = INT_MAX;
        for (int coin : coins) {
            int res = f(coins, rem - coin, dp);
            if (res >= 0 && res < mini) {
                mini = 1 + res;
            }
        }
        dp[rem] = (mini == INT_MAX) ? -1 : mini;
        return dp[rem];
    };

public:
    int coinChange(vector<int>& coins, int amnt) {
        vector<int> dp(amnt + 1, -2);
        return f(coins, amnt, dp);
    }
};