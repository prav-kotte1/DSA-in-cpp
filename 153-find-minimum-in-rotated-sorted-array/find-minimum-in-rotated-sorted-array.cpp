class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue<int , vector<int>, greater<int>> pq;
        pq.push(nums[0]);
        for(int num : nums){
            int i = pq.top();
            if(num < i){
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
    }
};