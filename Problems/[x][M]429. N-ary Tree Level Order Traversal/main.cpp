#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;

        queue<Node*> q;
        q.push(root);
        Node* cur;

        while (!q.empty()) {
            int curLevelLen = q.size();

            vector<int> curLevelNode;
            for (int i = 0; i < curLevelLen; i++) {
                cur = q.front();
                q.pop();
                curLevelNode.push_back(cur->val);
                for (auto n : cur->children) {
                    q.push(n);
                }
            }
            ans.push_back(curLevelNode);
        }

        return ans;
    }
};
int main() {
    cout << "[429. N-ary Tree Level Order Traversal]\n-----\n";
    Node* in1 = new Node(
        1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});

    auto ans1 = Solution().levelOrder(in1);
    return 0;
}