#include <bits/stdc++.h>
using namespace std;

// 同餘 https://ithelp.ithome.com.tw/articles/10205727
// http://www.sec.ntnu.edu.tw/Monthly/92(256-265)/261-PDF/2003-261-03(21-27).pdf
class Solution {
   public:
    const int MOD = 1e9 + 7;
    int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
    int lcm(int a, int b) { return a * b / gcd(a, b); }
    int nthMagicalNumber(int N, int A, int B) {
        long LCM = lcm(A, B), L = min(A, B), R = N * L, mid, ans;
        auto magicNumIndex = [&](long x) {
            return (x / A) + (x / B) - (x / LCM);
        };
        while (L <= R) {
            mid = L + (R - L) / 2;
            if (N <= magicNumIndex(mid)) {
                R = mid - 1;  // on right
            } else {
                L = mid + 1;  // on left
            }
        }
        ans = L;
        return ans % MOD;
    }
};

int main() {
    cout << Solution().nthMagicalNumber(1, 2, 3) << "\n";
    cout << Solution().nthMagicalNumber(4, 2, 3) << "\n";
    cout << Solution().nthMagicalNumber(5, 2, 4) << "\n";
    cout << Solution().nthMagicalNumber(3, 6, 4) << "\n";
    cout << Solution().gcd(120,60) << "\n";
    return 0;
}