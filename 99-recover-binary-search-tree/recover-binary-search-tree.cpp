/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // violation
        if (prev && prev->val > root->val) {

            // first violation
            if (!first) {
                first = prev;
            }

            // update second every time
            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        swap(first->val, second->val);
    }
};