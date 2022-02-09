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
};
int main() {
    cout << "532. " << '\n';

    vector<int> in1 = {3, 1, 4, 1, 5};
    cout << Solution().findPairs(in1, 2) << "\n";

    vector<int> in2 = {1, 2, 3, 4, 5};
    cout << Solution().findPairs(in2, 1) << "\n";

    vector<int> in3 = {1, 3, 1, 5, 4};
    cout << Solution().findPairs(in3, 0) << "\n";

    return 0;
}