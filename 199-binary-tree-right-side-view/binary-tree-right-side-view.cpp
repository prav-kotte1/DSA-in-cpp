/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelNodes = q.size();
            for (int i = 1; i <= levelNodes; i++) {
                TreeNode* curr = q.front();
                if (i == levelNodes) {
                    v.push_back(curr->val);
                }
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return v;
    }
};