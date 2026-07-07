class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int mid){
        long long hours=0;
        for(int p : piles){
            hours += (p + mid-1)/mid;
            if(hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while(l<r){
            int mid = l+(r-l)/2;
            if(canFinish(piles, h, mid))
                r=mid;
            else l=mid+1;
        }
        return l;
    }
};