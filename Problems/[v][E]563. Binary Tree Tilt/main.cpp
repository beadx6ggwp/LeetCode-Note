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

void insertNode(TreeNode *&root, const int k) {
    // bst
    if (root == nullptr) {
        root = new TreeNode(k);
    } else {
        if (k < root->val)
            insertNode(root->left, k);
        else
            insertNode(root->right, k);
    }
}

void insertNode2(TreeNode *&root, const int k) {
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
        insertNode2(t, n);
    }
    return t;
}
void inorder(TreeNode *temp) {
    if (temp == NULL) return;

    inorder(temp->left);
    cout << temp->val << ' ';
    inorder(temp->right);
}
class Solution {
   public:
    int tiltSum = 0;
    int findTilt(TreeNode *root) {
        DFS(root);
        return tiltSum;
    }
    int DFS(TreeNode *root) {
        if (!root) return 0;
        int leftSum = DFS(root->left);    // sum of left subtree
        int rightSum = DFS(root->right);  // sum of right subtree
        tiltSum += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};

int main() {
    TreeNode *test1 = createBinTree({4, 2, 9, 3, 5, 0, 7});
    inorder(test1);
    cout << "\n";
    cout << Solution().findTilt(test1);
    return 0;
}
