class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis){
        vis[node]=1;
        for(int nei : graph[node]){
            if(!vis[nei]){
                vis[nei]=1;
                dfs(nei, graph, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]){
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
            }
        }

        int comp=0;
        vector<int> vis(n, 0);
        for(int i=0; i<n;i++){
            if(!vis[i]){
                comp++;
                dfs(i, graph, vis);
            }
        }
        return n-comp;
    }
};