#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue != target) {
            if (target % 2 == 0 && startValue < target) {
                target /= 2;
            } else if (target > startValue) {
                target += 1;
            } else {
                ans += abs(target - startValue) - 1;
                target = startValue;
            }
            ans++;
        }
        return ans;
    }
};
int main() {
    cout << "[991. Broken Calculator]\n-----\n";

    // cout << Solution().brokenCalc(2, 3) << "\n";
    cout << Solution().brokenCalc(5, 8) << "\n";
    cout << Solution().brokenCalc(3, 10) << "\n";
    return 0;
}