#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildInPost(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int,int>& mp) {
    if (ps > pe || is > ie) return NULL;
    int rootVal = postorder[pe];
    int inRoot = mp[rootVal];
    int numsLeft = inRoot - is;
    TreeNode* root = new TreeNode(rootVal);
    root->left = buildInPost(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, mp);
    root->right = buildInPost(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, mp);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
    return buildInPost(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
    return 0;
}
