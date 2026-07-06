class Solution {
public:
    int minBitFlips(int start, int goal) {
        int r = start ^ goal;
        int cnt=0;
        while(r){
            r &=(r-1);
            cnt++;
        }
        return cnt;
    }
};