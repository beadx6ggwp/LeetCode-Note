#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        // int ans = 0;
        // for(auto n : nums){
        //     ans ^= n;
        // }
        // return ans;
        int l = 0, r = nums.size() - 2;
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;  //(r+l)/2

            // left side, move to right
            if (nums[mid] == nums[mid ^ 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }
};

int main() {
    vector<int> in1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> in2 = {3,3,7,7,10,11,11};
    cout << Solution().singleNonDuplicate(in1) << "\n";
    cout << Solution().singleNonDuplicate(in2) << "\n";

    return 0;
}