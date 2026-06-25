class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int mask) {

        if (mask == (1 << n) - 1)
            return 1;

        if (dp[mask] != -1)
            return dp[mask];

        int pos = __builtin_popcount(mask) + 1;

        int ways = 0;

        for (int num = 1; num <= n; num++) {

            int bit = num - 1;

            if (mask & (1 << bit))
                continue;

            if (num % pos == 0 || pos % num == 0) {
                ways += solve(mask | (1 << bit));
            }
        }

        return dp[mask] = ways;
    }

    int countArrangement(int n) {
        this->n = n;

        dp.assign(1 << n, -1);

        return solve(0);
    }
};