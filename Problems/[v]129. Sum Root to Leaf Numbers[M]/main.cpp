#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

int sum = 0;
void dfs(TreeNode *node, int num) {
    if (!node) return;
    num = num * 10 + node->val;
    if (!node->left && !node->right) {
        sum += num;
    }
    dfs(node->left, num);
    dfs(node->right, num);
}

int sumNumbers(TreeNode *root) {
    dfs(root, 0);
    return sum;
}

int main() {
    TreeNode r1(1, new TreeNode(2), new TreeNode(3));
    TreeNode r2(4, new TreeNode(9,new TreeNode(5),new TreeNode(1)), new TreeNode(0));
    cout << sumNumbers(&r2) << "\n";
    return 0;
}