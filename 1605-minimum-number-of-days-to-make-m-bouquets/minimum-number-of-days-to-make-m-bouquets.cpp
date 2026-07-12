class Solution {
public:
    bool f(vector<int>& b, int mid, int m, int k) {
        int cnt = 0;
        int B = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] <= mid) {
                cnt++;
            } else {
                B += (cnt / k);
                cnt = 0;
            }
        }
        B += (cnt / k);
        if (B >= m)
            return true;
        else
            return false;
    }
    int minDays(vector<int>& b, int m, int k) {
        if ((long long)m * k > b.size())
            return -1;

        int l = *min_element(b.begin(), b.end());
        int r = *max_element(b.begin(), b.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(b, mid, m, k) == true)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};