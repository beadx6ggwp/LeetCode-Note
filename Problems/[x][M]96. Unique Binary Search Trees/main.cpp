#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C%2B%2BPython-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)
// https://medium.com/@bill800227/leetcode-96-unique-binary-search-trees-abce6e62a7a0
// https://ithelp.ithome.com.tw/articles/10213289
class Solution {
   public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++) dp[i] += dp[j] * dp[i - j - 1];
        return dp[n];
    }
};

int main() {
    cout << Solution().numTrees(3) << '\n';
    cout << Solution().numTrees(1) << '\n';
    return 0;
}