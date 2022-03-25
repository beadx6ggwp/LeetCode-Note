#include <bits/stdc++.h>
using namespace std;
// 給定長度2n的陣列每項為[A,B] 表示去A與B的cost，找出最少的cost，並確保有N個人去其中一個城市
// 也就是說A與B各要去一半的人
class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int w = 0;
        vector<int> diff;
        int total = 0, totalB = 0;
        for (auto cost : costs) {
            diff.push_back(cost[1] - cost[0]);
            total += cost[0];
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < costs.size() / 2; i++) {
            total += diff[i];
        }
        return total;
    }
};
int main() {
    cout << "[1029. Two City Scheduling]\n-----\n";
    vector<vector<int>> in1 = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};

    vector<vector<int>> in2 = {{259, 770}, {448, 54},  {926, 667},
                               {184, 139}, {840, 118}, {577, 469}};

    cout << Solution().twoCitySchedCost(in2);
    return 0;
}