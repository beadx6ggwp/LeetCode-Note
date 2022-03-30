#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int size = rows * cols;
        auto getByInd = [&](int ind) { return matrix[ind / cols][ind % cols]; };

        int l = 0, r = size - 1, mid, val;
        while (l <= r) {
            mid = l + (r - l) / 2;
            val = getByInd(mid);
            if (val == target) 
                return 1;

            if (val < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return 0;
    }
};
int main() {
    cout << "[74. Search a 2D Matrix]\n-----\n";
    vector<vector<int>> in1 = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << Solution().searchMatrix(in1, 3) << "\n";

    vector<vector<int>> in2 = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << Solution().searchMatrix(in1, 13) << "\n";

    return 0;
}