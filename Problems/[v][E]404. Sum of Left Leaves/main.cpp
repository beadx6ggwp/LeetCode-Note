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

int dfs(TreeNode *node, bool isLeft) {
    if (!node) return 0;
    if (!node->left && !node->right) return isLeft ? node->val : 0;
    return dfs(node->left, true) + dfs(node->right, false);
}

int sumOfLeftLeaves(TreeNode *root) { return dfs(root, false); }

// int sumOfLeaves(TreeNode *root) {
//     if (!root) return 0;
//     if (!root->left && !root->right) return root->val;
//     return sumOfLeaves(root->left) + sumOfLeaves(root->right) +
//            root->val;
// }

int main() {
    TreeNode r2(3, new TreeNode(9),
                new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout << sumOfLeftLeaves(&r2) << "\n";
    return 0;
}