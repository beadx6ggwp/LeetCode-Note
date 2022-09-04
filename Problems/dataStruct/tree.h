#pragma once
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void insertBstNode(TreeNode *&root, const int k) {
    // bst
    if (root == nullptr) {
        root = new TreeNode(k);
    } else {
        if (k < root->val)
            insertBstNode(root->left, k);
        else
            insertBstNode(root->right, k);
    }
}

void insertBinNode(TreeNode *&root, const int k) {
    // binary tree;
    if (root == nullptr) {
        root = new TreeNode(k);
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *now = q.front();
        q.pop();

        if (now->left == nullptr) {
            now->left = new TreeNode(k);
            return;
        } else {
            q.push(now->left);
        }

        if (now->right == nullptr) {
            now->right = new TreeNode(k);
            return;
        } else {
            q.push(now->right);
        }
    }
}

TreeNode *createBinTree(vector<int> nums) {
    TreeNode *t = nullptr;
    for (auto n : nums) {
        insertBinNode(t, n);
    }
    return t;
}
TreeNode *createBinTreeByString(string input, char splitChar,
                                string nullNodeStr = "null") {
    // TreeNode *t = createBinTreeByString("3,9,20,null,null,15,7", ',');
    TreeNode *root = nullptr;
    stringstream ss(input);
    string tok;
    int num;
    // std::getline(ss, tok, splitChar);

    std::getline(ss, tok, splitChar);
    if (tok == nullNodeStr)
        return root;
    else
        root = new TreeNode(stoi(tok));

    queue<TreeNode *> q;
    q.push(root);
    while (std::getline(ss, tok, splitChar)) {
        TreeNode *now = q.front();
        q.pop();

        if (tok != nullNodeStr && now->left == nullptr) {
            now->left = new TreeNode(stoi(tok));
            q.push(now->left);
        }
        std::getline(ss, tok, splitChar);
        if (tok != nullNodeStr && now->right == nullptr) {
            now->right = new TreeNode(stoi(tok));
            q.push(now->right);
        }
    }

    return root;
}
void inorder(TreeNode *temp) {
    if (temp == NULL) return;

    inorder(temp->left);
    cout << temp->val << ' ';
    inorder(temp->right);
}

// int main() {
//     TreeNode *test1 = createBinTree({4, 2, 9, 3, 5, 0, 7});
//     inorder(test1);
//     cout << "\n";
//     return 0;
// }
