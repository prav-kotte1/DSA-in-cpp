class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char c: s)
            mp[c]++;
        int n = s.size();

        for(auto & it: mp){
            if(it.second >(n+1)/2){
                return "";
            }
        }
        string ans = "";
        priority_queue<pair<int, char>> pq;
        for(auto& it: mp) pq.push({it.second, it.first});
        while(pq.size()>=2){
            auto [freq1, char1] = pq.top(); pq.pop();
            auto [freq2, char2] = pq.top(); pq.pop();
            ans += char1;
            ans += char2;

            if(freq1-1 > 0) pq.push({freq1-1, char1});
            if(freq2-1 > 0) pq.push({freq2-1, char2});
        }

        if(!pq.empty()){
            ans += pq.top().second;
        }
        return ans;
    }
};