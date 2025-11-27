#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->key == key) return root;
    if (key < root->key) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root && root->key != key) {
        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* findMin(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* curr = root;
    Node* succ = NULL;
    while (curr) {
        if (key < curr->key) {
            succ = curr;
            curr = curr->left;
        } else if (key > curr->key) {
            curr = curr->right;
        } else {
            if (curr->right) succ = findMin(curr->right);
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    while (curr) {
        if (key > curr->key) {
            pred = curr;
            curr = curr->right;
        } else if (key < curr->key) {
            curr = curr->left;
        } else {
            if (curr->left) pred = findMax(curr->left);
            break;
        }
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int a[] = {20, 10, 30, 5, 15, 25, 35};
    for (int x : a) root = insertNode(root, x);
    Node* r1 = searchRec(root, 15);
    Node* r2 = searchIter(root, 25);
    Node* mn = findMin(root);
    Node* mx = findMax(root);
    Node* s = inorderSuccessor(root, 15);
    Node* p = inorderPredecessor(root, 25);
    return 0;
}
