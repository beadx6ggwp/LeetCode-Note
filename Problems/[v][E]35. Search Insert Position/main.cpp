#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> in1 = {1, 3, 5, 6};

    cout << Solution().searchInsert(in1, 5);

    return 0;
}