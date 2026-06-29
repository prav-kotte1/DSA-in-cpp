class Solution {
public:
    int maxProfit(vector<int>& p, int f) {
        int n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy == 0){ //looking to buy
                    profit = max(dp[i+1][0], -p[i]+dp[i+1][1]); //skip or buy
                }
                if(buy == 1){//looking to sell
                    profit = max(dp[i+1][1], p[i] - f + dp[i+1][0]); //skip or sell
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
};