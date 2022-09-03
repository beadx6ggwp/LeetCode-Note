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
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();  // 取出這層有幾個
            double sum = 0;
            // 把這層的全都推出來加總，並推下推一層的node
            for (size_t i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                sum += node->val;
            }
            ans.push_back(sum / size);
        }
        return ans;
    }
};
int main() {
    cout << "[637. Average of Levels in Binary Tree]\n-----\n";
    TreeNode *node =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    auto ans1 = Solution().averageOfLevels(node);
    for (auto d : ans1) printf("%f ", d);
    return 0;
}