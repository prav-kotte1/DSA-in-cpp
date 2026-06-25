class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols

        int t = 0, b = m-1, l = 0, r = n-1; //boundaries
        /* 1. l to r t++
           2. t to b r--
           3. if(t <= b) r to l b--
           4. if(l <= r) b to t l++ */
        vector<int> ans;
        while(t <= b && l <= r){
            for(int j=l; j<= r; j++) ans.push_back(matrix[t][j]); t++;
            for(int i=t; i<= b; i++) ans.push_back(matrix[i][r]); r--;
            if(t<=b)for(int j=r; j>= l; j--) ans.push_back(matrix[b][j]); b--;
            if(l<=r)for(int i=b; i>= t; i--) ans.push_back(matrix[i][l]); l++;
        }
        return ans;
    }
};