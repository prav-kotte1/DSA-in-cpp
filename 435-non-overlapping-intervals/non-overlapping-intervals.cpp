class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int prevEnd = intervals[0][1];
        int c = 0; // overlap count
        for (int i = 1; i < intervals.size(); i++) {
            // overlap
            if (intervals[i][0] < prevEnd) {
                c++;
            } else { // no overlap
                prevEnd = intervals[i][1];
            }
        }
        return c;
    }
};