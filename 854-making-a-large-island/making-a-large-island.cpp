class DisjointSet{
   
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);

        if(upu == upv) return;
        if(size[upu] < size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        } else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution {
public:
    bool isValid(int adjr, int adjc, int n){
        return adjr>=0 && adjc >= 0 && adjr < n && adjc < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        DisjointSet ds(n*n);
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};

                for(int ind=0; ind<4; ind++){
                    int adjr = dr[ind] + row;
                    int adjc = dc[ind] + col;
                    if(isValid(adjr, adjc, n) && grid[adjr][adjc] == 1){
                        int adjNodeNo = adjr * n + adjc;
                        ds.UnionBySize(row*n + col, adjNodeNo);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;
                for(int ind=0; ind<4; ind++){
                    int adjr = dr[ind] + row;
                    int adjc = dc[ind] + col;
                    if(isValid(adjr, adjc, n)){
                        if(grid[adjr][adjc] == 1){
                            components.insert(ds.findUltimateParent(adjr*n + adjc));
                        }
                    }
                }
                int sizeTotal =1;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal);
            }
        }

        for(int cellNo =0; cellNo <n*n; cellNo++){
            mx = max(mx, ds.size[ds.findUltimateParent(cellNo)]);
        }
        return mx;
    }
};