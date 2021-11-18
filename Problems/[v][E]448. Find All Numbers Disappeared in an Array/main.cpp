#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));  // insert every nums[i] in hashset
        vector<int> ans(nums.size() - s.size());
        for (int i = 1, j = 0; i <= nums.size(); i++)
            if (!s.count(i))
                ans[j++] = i;  // add all elements not found in hashset to ans
        return ans;
    }
};

int main() {
    vector<int> in1 = {4, 3, 2, 7, 8, 2, 3, 1};  //[5.6]
    vector<int> in2 = {1, 1};                    //[2]
    vector<int> in3 = {1, 1, 2, 2};              //[3,4]

    // auto outt = Solution().findDisappearedNumbers(in3);
    auto out1 = Solution().findDisappearedNumbers(in1);
    auto out2 = Solution().findDisappearedNumbers(in2);
    cout << "123"
         << "\n";
    return 0;
}