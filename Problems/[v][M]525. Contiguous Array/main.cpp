#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] << 1) - 1;
            // 如果這個sum存在過，去查表取得這個sum第一次出現的index
            // 讓當前i - index，就可知道目前最長的長度
            if (m.count(sum)) {
                ans = max(ans, i - m[sum]);
            } else {
                m[sum] = i;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> in1 = {0, 1};
    vector<int> in2 = {0, 1, 0};
    vector<int> in3 = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0};

    cout << Solution().findMaxLength(in1) << "\n";
    cout << Solution().findMaxLength(in2) << "\n";
    cout << Solution().findMaxLength(in3) << "\n";

    return 0;
}