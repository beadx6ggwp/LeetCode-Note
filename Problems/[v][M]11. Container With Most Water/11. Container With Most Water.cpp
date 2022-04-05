#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            // area = dist * min-height, (r-l)*height[min]
            area = max(area, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return area;
    }
};
int main() {
    cout << "[11. Container With Most Water]\n-----\n";
    vector<int> in1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution().maxArea(in1);

    return 0;
}