#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root, bool isLeft) {
    if (!root) return 0;
    if (!root->left && !root->right) return isLeft ? root->val : 0;
    return dfs(root->left, true) + dfs(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root, false);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int s = sumOfLeftLeaves(root);
    return 0;
}
