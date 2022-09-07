#include <bits/stdc++.h>
using namespace std;
#include "../dataStruct/tree.h"

class Solution {
    TreeNode *rec(TreeNode *node) {
        if (node->left) node->left = rec(node->left);
        if (node->right) node->right = rec(node->right);
        if (node->left == nullptr && node->right == nullptr && node->val == 0) {
            delete node;
            return nullptr;
        }
        return node;
    }

   public:
    TreeNode *pruneTree(TreeNode *root) {
        TreeNode *ans;
        ans = rec(root);
        return ans;
    }
};

int main() {
    cout << "[814. Binary Tree Pruning]\n-----\n";

    TreeNode *in1 = createBinTreeByString("1,null,0,0,1", ',');
    auto out1 = Solution().pruneTree(in1);

    TreeNode *in2 = createBinTreeByString("1,0,1,0,0,0,1", ',');
    auto out2 = Solution().pruneTree(in2);

    return 0;
}