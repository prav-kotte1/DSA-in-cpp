class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, z=0;
        int maxL=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r] == 0){
                z++;
            }
            if(z > k){
                if(nums[l] == 0) z--;
                l++;
            }
            maxL = max(maxL, r-l+1);
        }
        return maxL;
    }
};