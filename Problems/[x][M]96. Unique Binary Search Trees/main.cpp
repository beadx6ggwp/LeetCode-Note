#include <bits/stdc++.h>
using namespace std;

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