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
TreeNode *createBinTree(vector<int> nums) {
    TreeNode *t = nullptr;
    for (auto n : nums) {
        insertNode(t, n);
    }
    return t;
}
class Solution {
   public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        TreeNode *now = root;
        queue<TreeNode *> q;
        q.push(now);

        int sum = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->val >= low && node->val <= high) {
                sum += node->val;
            }
            if (node->left && node->val > low) {
                q.push(node->left);
            }
            if (node->right && node->val < high) {
                q.push(node->right);
            }
        }

        return sum;
    }
};

int main() {
    TreeNode *tree1 = createBinTree({10, 5, 15, 3, 7, 0, 18});
    TreeNode *tree2 = createBinTree({10, 5, 15, 3, 7, 13, 18, 1, 0, 6});

    cout << Solution().rangeSumBST(tree1, 7, 15) << "\n";
    cout << Solution().rangeSumBST(tree2, 6, 10) << "\n";
    return 0;
}