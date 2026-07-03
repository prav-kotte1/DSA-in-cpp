class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = n - 2; i >= 1; i--) {
            for (int j = i; j <= n - 2; j++) {
                int maxi = 0;
                for (int k = i; k <= j; k++) {
                    int left = (k > i) ? dp[i][k - 1] : 0;
                    int right = (k < j) ? dp[k + 1][j] : 0;
                    int coins =
                        nums[i - 1] * nums[k] * nums[j + 1] + left + right;
                    maxi = max(coins, maxi);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};