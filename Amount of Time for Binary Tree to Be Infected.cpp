class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

public:
    int amountOfTime(TreeNode* root, int start) {
        parent[root] = nullptr;
        populateParents(root);
        auto startNode = findNode(root, start);
        queue<TreeNode*> que;
        que.push(startNode);
        unordered_set<TreeNode*> visited;
        visited.insert(startNode);
        int level = -1;
        while (!que.empty()) {
            level++;
            int levelSize = que.size();
            while (levelSize--) {
                auto node = que.front();
                que.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    que.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    que.push(node->right);
                    visited.insert(node->right);
                }
                if (parent[node] &&
                    visited.find(parent[node]) == visited.end()) {
                    que.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
        }
        return level;
    }

private:
    void populateParents(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            parent[root->left] = root;
            populateParents(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            populateParents(root->right);
        }
    }
    TreeNode* findNode(TreeNode* root, int start) {
        if (!root)
            return root;
        if (root->val == start)
            return root;
        auto left = findNode(root->left, start);
        if (left)
            return left;
        return findNode(root->right, start);
    }
};
