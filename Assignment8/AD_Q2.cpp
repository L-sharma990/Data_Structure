#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeList {
    TreeNode* tree;
    TreeList* next;
    TreeList(TreeNode* t) : tree(t), next(NULL) {}
};

class Solution {
public:
    TreeList* build(int l, int r) {
        if (l > r) {
            return new TreeList(NULL); 
        }
        
        TreeList* res = NULL;
        
        for (int i = l; i <= r; ++i) {
            TreeList* leftTrees = build(l, i - 1);
            TreeList* rightTrees = build(i + 1, r);
            
            for (TreeList* L = leftTrees; L != NULL; L = L->next) {
                for (TreeList* R = rightTrees; R != NULL; R = R->next) {
                    TreeNode* root = new TreeNode(i);
                    root->left = L->tree;
                    root->right = R->tree;
                    
                    TreeList* newNode = new TreeList(root);
                    newNode->next = res;
                    res = newNode;
                }
            }
        }
        return res;
    }
    
    TreeList* generateTrees(int n) {
        if (n == 0) return NULL;
        return build(1, n);
    }
};

int main() {
    Solution s;
    TreeList* trees = s.generateTrees(3);
    
    int count = 0;
    TreeList* curr = trees;
    while(curr) {
        count++;
        curr = curr->next;
    }
    
    cout << "Generated " << count << " trees." << endl;
    return 0;
}
