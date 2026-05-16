class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0, farthest=0, currEnd=0;
        for(int i=0; i<n-1;i++){
            farthest = max(farthest, i+nums[i]);
            if(farthest >= n-1){
                ++ans; break;
            }
            if(i==currEnd){
                ++ans; currEnd = farthest;
            }
        }
        return ans;
    }
};