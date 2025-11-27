#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildPreIn(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int,int>& mp) {
    if (ps > pe || is > ie) return NULL;
    int rootVal = preorder[ps];
    int inRoot = mp[rootVal];
    int numsLeft = inRoot - is;
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildPreIn(preorder, ps + 1, ps + numsLeft, inorder, is, inRoot - 1, mp);
    root->right = buildPreIn(preorder, ps + numsLeft + 1, pe, inorder, inRoot + 1, ie, mp);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
    return buildPreIn(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorder, inorder);
    return 0;
}
