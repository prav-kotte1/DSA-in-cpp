class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<pair<int,int>> arr;
        for(auto& it: freq){
            arr.push_back({it.second, it.first}); //freq, element
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};