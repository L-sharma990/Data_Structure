#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int x) : val(x), prev(NULL), next(NULL) {}
};

void inorderCollect(TreeNode* root, vector<int>& v) {
    if (!root) return;
    inorderCollect(root->left, v);
    v.push_back(root->val);
    inorderCollect(root->right, v);
}

DLLNode* mergeBSTsToDLL(TreeNode* root1, TreeNode* root2) {
    vector<int> a, b;
    inorderCollect(root1, a);
    inorderCollect(root2, b);
    vector<int> c;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while (i < a.size()) c.push_back(a[i++]);
    while (j < b.size()) c.push_back(b[j++]);
    if (c.empty()) return NULL;
    DLLNode* head = new DLLNode(c[0]);
    DLLNode* curr = head;
    for (int k = 1; k < c.size(); ++k) {
        DLLNode* node = new DLLNode(c[k]);
        curr->next = node;
        node->prev = curr;
        curr = node;
    }
    return head;
}

int main() {
    TreeNode* t1 = new TreeNode(20);
    t1->left = new TreeNode(10);
    t1->right = new TreeNode(30);
    t1->left->left = new TreeNode(5);
    t1->left->right = new TreeNode(25);
    t1->right->right = new TreeNode(50);

    TreeNode* t2 = new TreeNode(5);
    t2->right = new TreeNode(70);

    DLLNode* head = mergeBSTsToDLL(t1, t2);
    
    DLLNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
