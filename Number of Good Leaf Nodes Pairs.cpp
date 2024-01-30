class Solution {
public:
    int ans = 0;
    vector<int> f(TreeNode* curr, int dis) {
        if (curr == nullptr) {
            return {};
        }
        if (!curr->left and !curr->right) {
            return {1};
        }
        auto left = f(curr->left, dis);
        auto right = f(curr->right, dis);
        if (!left.empty() and !right.empty()) {
            vector<int> ret;
            sort(right.begin(), right.end());
            for (auto iter : left) {
                int pos = upper_bound(right.begin(), right.end(), dis - iter) -
                          right.begin();
                ans = ans + pos;
            }
        }
        for (int i = 0; i < right.size(); i++) {
            right[i]++;
        }
        for (auto iter : left) {
            right.push_back(iter + 1);
        }
        return right;
    }
    int countPairs(TreeNode* root, int distance) {
        f(root, distance);
        return ans;
    }
};
