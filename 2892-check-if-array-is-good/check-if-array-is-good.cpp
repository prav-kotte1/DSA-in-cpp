class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        map<int,int> freq;
        for(int x : nums) freq[x]++;
        
        int check=1; 
        for(auto [k,x] : freq){
            if(k<n-1 && x==1 && k==check) check++;
            else if(k==n-1 && x==2 && k==check) return true;
            else return false;
        }
        return true;
    }
};