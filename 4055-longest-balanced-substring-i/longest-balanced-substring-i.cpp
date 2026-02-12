class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int res=0;
        vector<int> cnt(26);
        for(int i=0;i<n;i++){
            fill(cnt.begin(),cnt.end(),0);
            for(int j=i;j<n;j++){
                bool f=true;
                int c=s[j]-'a';
                cnt[c]++;
                for(auto x:cnt){
                    if(x>0 && x!=cnt[c]){
                        f=false;break;
                    }
                }
                if(f){
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
    }
};