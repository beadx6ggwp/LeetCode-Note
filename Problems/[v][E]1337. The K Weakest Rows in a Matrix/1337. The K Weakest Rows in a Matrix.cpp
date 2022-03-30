#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        vector<int> ans(k);
        for (int i = 0; i < mat.size(); i++) mat[i].push_back(i);
        sort(mat.begin(), mat.end());
        for (int i = 0; i < k; i++) ans[i] = mat[i][n];
        return ans;
    }
};
int main() {
    cout << "[1337. The K Weakest Rows in a Matrix]\n-----\n";
    vector<vector<int>> in1 = {{1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 0},
                               {1, 0, 0, 0, 0},
                               {1, 1, 0, 0, 0},
                               {1, 1, 1, 1, 1}};
    auto ans1 = Solution().kWeakestRows(in1, 3);
    return 0;
}