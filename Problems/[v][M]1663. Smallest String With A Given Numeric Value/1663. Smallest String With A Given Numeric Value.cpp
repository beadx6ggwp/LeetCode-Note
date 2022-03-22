#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        int last = res.size() - 1;
        while (k >= 0 && last >= 0) {
            if (k >= 26) {
                res[last--] = 'z';
            } else {
                res[last--] = (char)(k + 'a');
            }
            k -= 25;
        }

        return res;
    }
};
int main() {
    cout << "[1663. Smallest String With A Given Numeric Value]\n-----\n";
    // cout << Solution().getSmallestString(3, 27) << "\n";
    cout << Solution().getSmallestString(5, 130) << "\n";
    return 0;
}