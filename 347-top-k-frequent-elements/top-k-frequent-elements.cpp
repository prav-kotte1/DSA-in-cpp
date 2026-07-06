class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto& it: freq){
            pq.push({it.second, it.first}); //freq, element
        }

        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};