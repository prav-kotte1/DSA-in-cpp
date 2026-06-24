class Solution {
private:
    int f(int ind, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = f(ind-1, nums, target, dp);
        int take = 0;
        if(nums[ind] <= target){
            take = f(ind-1, nums, target-nums[ind], dp);
        }
        return dp[ind][target] = take + notTake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums) sum += num;
        int p = (sum + target)/2;
        if(sum + target < 0) return 0;
        if((sum + target)%2) return 0;
        vector<vector<int>> dp(nums.size(), vector<int> (p+1, -1));
        return f(nums.size()-1, nums, p, dp);
    }
};