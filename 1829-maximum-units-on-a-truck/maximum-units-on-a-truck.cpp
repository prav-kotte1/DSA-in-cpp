class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int t) {
        
        sort(bt.begin(), bt.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });

        int ans = 0;

        for (auto& box : bt) {
            int boxes = min(t, box[0]);

            ans += boxes * box[1];
            t -= boxes;

            if (t == 0) break;
        }

        return ans;
    }
};