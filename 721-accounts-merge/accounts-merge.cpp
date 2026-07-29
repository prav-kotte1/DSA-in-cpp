class DisjointSet {
vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findUltiParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltiParent(parent[node]);
    }

    void UnionByRank(int u, int v){
        int upU = findUltiParent(u);
        int upV = findUltiParent(v);
        if(upU == upV) return;
        if(rank[upU] < rank[upV]) parent[upU] = upV;
        else if(rank[upV] < rank[upU]) parent[upV] = upU;
        else { 
            parent[upV] = upU; 
            rank[upU]++;
        }
    }

    void UnionBySize(int u, int v){
        int upU = findUltiParent(u);
        int upV = findUltiParent(v);
        if(upU == upV) return;
        if(size[upU] < size[upV]){
            parent[upU] = upV;
            size[upV] += size[upU];
        } else {
            parent[upV] = upU;
            size[upU] += size[upV];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                } else {
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUltiParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i=0; i<n; i++){
            if(mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};