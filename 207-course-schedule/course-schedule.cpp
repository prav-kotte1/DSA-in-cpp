class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pre) {
        vector<vector<int>> adj(nc);
        vector<int> indegree(nc, 0);

        for(auto& p : pre){
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0; i<nc; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int comp = 0; //completed
        while(!q.empty()){
            int node = q.front();
            q.pop();
            comp++;
            for(auto& nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return comp == nc;
    }
};