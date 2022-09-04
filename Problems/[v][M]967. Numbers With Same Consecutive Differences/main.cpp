#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> result;
    void makeNum(int ans, int len, int k) {
        if (len == 0) {
            // printf("%d\n", ans);
            result.push_back(ans);
            return;
        }
        int lastNum = ans % 10;
        ans *= 10;

        for (int i = 0; i <= 9; i++) {
            if (abs(lastNum - i) == k) {
                makeNum(ans + i, len - 1, k);
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (size_t i = 1; i <= 9; i++) makeNum(i, n - 1, k);

        return result;
    }
};
int main() {
    cout << "[967. Numbers With Same Consecutive Differences]\n-----\n";
    Solution().numsSameConsecDiff(2, 1);
    return 0;
}