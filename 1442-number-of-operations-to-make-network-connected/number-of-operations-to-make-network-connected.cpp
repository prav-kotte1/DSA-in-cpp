class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(int nei: adj[node]){
            if(!vis[nei]){
                dfs(nei, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<vector<int>> adj(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int comp = 0;
        for(int i=0; i<n;i++){
            if(vis[i] == 0){
                comp++;
                dfs(i, adj, vis);
            }
        }
        return comp-1;
    }
};