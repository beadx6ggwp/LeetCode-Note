#include <bits/stdc++.h>

#include "../dataStruct/tree.h"
using namespace std;

class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        traverse(root, 0, 0, nodes);
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

   private:
    void traverse(TreeNode* root, int x, int y,
                  map<int, map<int, multiset<int>>>& nodes) {
        if (root) {
            nodes[x][y].insert(root->val);
            traverse(root->left, x - 1, y + 1, nodes);
            traverse(root->right, x + 1, y + 1, nodes);
        }
    }
};
int main() {
    cout << "[987. Vertical Order Traversal of a Binary Tree]\n-----\n";
    TreeNode* input1 = createBinTree({1, 2, 3, 4, 5, 6, 7});
    TreeNode* input2 = createBinTree({1, 2, 3, 4, 6, 5, 7});
    auto ans1 = Solution().verticalTraversal(input1);
    auto ans2 = Solution().verticalTraversal(input2);
    return 0;
}