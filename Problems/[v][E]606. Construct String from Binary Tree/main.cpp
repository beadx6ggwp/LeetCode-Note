#include <bits/stdc++.h>

#include "../dataStruct/tree.h"
using namespace std;

class Solution {
    void rec(TreeNode* node, string& str) {
        str += to_string(node->val);
        if (node->left) {
            str += "(";
            rec(node->left, str);
            str += ")";
        }
        if (node->right) {
            // 如果右子樹有，左子樹要補一個空的
            if (!node->left) str += "()";
            str += "(";
            rec(node->right, str);
            str += ")";
        }
        return;
    }

   public:
    string tree2str(TreeNode* root) {
        string ans = "";
        rec(root, ans);
        return ans;
    }
    /*
    這樣比較慢，應該是string用pass by val的關係，上面的是用by ref
    public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string ans = to_string(root->val);
        if (root->left) {
            ans += "(" + tree2str(root->left) + ")";
        }
        if (root->right) {
            if (!root->left) ans += "()";
            ans += "(" + tree2str(root->right) + ")";
        }

        return ans;
    }
    */
};
int main() {
    cout << "[606. Construct String from Binary Tree]\n-----\n";
    TreeNode* in1 = createBinTreeByString("1,2,3,4", ',');
    TreeNode* in2 = createBinTreeByString("1,2,3,null,4", ',');

    auto out1 = Solution().tree2str(in1);
    auto out2 = Solution().tree2str(in2);
    return 0;
}