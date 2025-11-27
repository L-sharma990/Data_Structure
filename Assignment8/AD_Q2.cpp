#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {NULL};
        vector<TreeNode*> res;
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> leftTrees = build(l, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, r);
            for (auto L : leftTrees) {
                for (auto R : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = L;
                    root->right = R;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};

int main() {
    Solution s;
    vector<TreeNode*> trees = s.generateTrees(3);
    return 0;
}
