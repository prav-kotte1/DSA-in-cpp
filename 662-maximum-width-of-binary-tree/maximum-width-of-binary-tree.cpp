/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        unsigned long long f=0, l=0, w=0;
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s;i++){
                auto [node, ind]=q.front(); q.pop();
                if(node->left) q.push({node->left, (ind*2 -1)});
                if(node->right) q.push({node->right, (ind*2)});
                if(i==0) f=ind;
                if(i==s-1) l=ind;
            }
            w = max(w, l-f+1);
        }
        return w;
    }
};