#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], ans = nums[0];
        vector<int> f(nums.size());
        f[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            sum = max(sum + nums[i], nums[i]);
            if (sum > ans) ans = sum;
        }
        return ans;
    }
};

int main() {
    vector<int> in1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> in2 = {1};
    vector<int> in3 = {5, 4, -1, 7, 8};
    cout << Solution().maxSubArray(in1) << "\n";
    cout << Solution().maxSubArray(in2) << "\n";
    cout << Solution().maxSubArray(in3) << "\n";
    return 0;
}