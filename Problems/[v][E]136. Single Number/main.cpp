#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto n : nums) {
            ans ^= n;
        }
        return ans;
    }
};

int main() {
    vector<int> in1 = {2, 2, 1};
    vector<int> in2 = {4, 1, 2, 1, 2};
    vector<int> in3 = {1};
    cout << Solution().singleNumber(in1) << "\n";
    cout << Solution().singleNumber(in2) << "\n";
    cout << Solution().singleNumber(in3) << "\n";
    return 0;
}