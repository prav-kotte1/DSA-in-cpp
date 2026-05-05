/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj) {
        if (!root) return;

        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            buildGraph(root->left, adj);
        }

        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            buildGraph(root->right, adj);
        }
    }

    TreeNode* findTarget(TreeNode* root, int target) {
        if (!root) return NULL;
        if (root->val == target) return root;

        TreeNode* left = findTarget(root->left, target);
        if (left) return left;

        return findTarget(root->right, target);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        buildGraph(root, adj);

        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> visited;

        q.push({target, 0});
        visited.insert(target);

        vector<int> result;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist == k) {
                result.push_back(node->val);
            }

            if (dist > k) break;

            for (auto neighbor : adj[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return result;
    }
};