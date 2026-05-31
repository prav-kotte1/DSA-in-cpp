class Solution {
private:
    void dfs(int node, vector<vector<int>>& isC, vector<int>& vis){
        vis[node] = 1;
        for(int nei = 0; nei <isC.size(); nei++){
            if(isC[node][nei] == 1 && !vis[nei]){
                dfs(nei, isC, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isC) {
        int n = isC.size();
        vector<int> vis(n, 0);
        int res = 0; 

        for(int i=0; i<n; i++){
            if(!vis[i]){
                res++;
                dfs(i, isC, vis);
            }
        }
        return res;
    }
};