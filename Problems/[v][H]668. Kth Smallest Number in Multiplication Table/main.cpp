#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findKthNumber(int m, int n, int k) {
        // Binary search
        int low = 0, high = m * n, mid;

        while ((low <= high)) {
            mid = low + (high - low) / 2;
            int index = findNumberMaxKth(m, n, mid);
            if (k <= index) {
                // change up bound
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    int findNumberMaxKth(int m, int n, int num) {
        int kth = 0;
        if (m * n < num) return -1;
        for (int y = 1; y <= m; y++) {
            // y*(1~n)
            // 如果num大於第y層，那就加上y層的n個數字
            // 如果num就在第y層，那就透過num/y，來看它屬於第幾個
            // if (num / y >= n) kth += n;
            // else kth += num / y;
            kth += min(num / y, n);
        }
        return kth;
    }
};

int main() {
    cout << Solution().findNumberMaxKth(1, 3, 2) << "\n";
    cout << Solution().findKthNumber(4, 4, 10) << "\n";     // 6
    cout << Solution().findKthNumber(42, 34, 401) << "\n";  // 126
    return 0;
}