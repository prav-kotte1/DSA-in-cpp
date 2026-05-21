class Solution {
public:

    bool solve(TreeNode* root, long long low, long long high) {

        if (root == NULL)
            return true;

        // current node violates BST rule
        if (root->val <= low || root->val >= high)
            return false;

        // left subtree:
        // values must be < root->val

        // right subtree:
        // values must be > root->val

        return solve(root->left, low, root->val) &&
               solve(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {

        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};