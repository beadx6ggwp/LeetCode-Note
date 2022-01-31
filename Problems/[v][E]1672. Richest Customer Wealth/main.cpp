#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = 0;
        for (auto arr : accounts) {
            int sum = 0;
            for (auto num : arr) {
                sum += num;
            }
            m = std::max(sum, m);
        }
        return m;
    }
};
int main() {
    vector<vector<int>> in1 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    cout << Solution().maximumWealth(in1);

    return 0;
}