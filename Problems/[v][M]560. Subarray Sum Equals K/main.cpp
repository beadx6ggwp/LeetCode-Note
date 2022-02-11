#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
class Solution {
   public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }
        int count = 0;
        for (auto it : m) {
            int _k = it.first, _v = it.second;
            if (k != 0 && m.count(_k + k) ||
                k == 0 && m.count(_k) && m[_k] > 1) {
                count++;
            }
        }
        return count;
    }
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        for (auto n : nums) {
            m[n]++;
        }

        for (auto n : nums) {
            int diff = k - n;
            if (m.count(diff) && m[diff] > 0) {
                count++;
                m[diff]--;
            }
        }
        return count;
    }
};
int main() {
    cout << "560. " << '\n';

    vector<int> in1 = {1, 1, 1};
    // cout << Solution().subarraySum(in1, 2) << "\n";

    vector<int> in2 = {1, 2, 3};
    cout << Solution().subarraySum(in2, 3) << "\n";

    return 0;
}