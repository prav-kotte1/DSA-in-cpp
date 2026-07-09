class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
    int atMost(vector<int> &nums, int k){
        int i=0, res=0;
        unordered_map<int, int> freq;
        for(int j=0; j<nums.size(); ++j){
            if(!freq[nums[j]]++) k--;
            while(k<0){
                if(!--freq[nums[i]]) k++;
                i++;
            }
            res+= j-i+1;
        }
        return res;
    }
};