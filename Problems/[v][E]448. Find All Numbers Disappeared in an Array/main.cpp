#include <bits/stdc++.h>

#include <unordered_set>
using namespace std;

class Solution {
   public:
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     unordered_set<int> s(begin(nums), end(nums));  // insert every
    //     nums[i] in hashset vector<int> ans(nums.size() - s.size()); for (int
    //     i = 1, j = 0; i <= nums.size(); i++)
    //         if (!s.count(i))
    //             ans[j++] = i;  // add all elements not found in hashset to
    //             ans
    //     return ans;
    // }
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     // time:O(n), spzec:O(1)
    //     vector<int> ans;
    //     for (auto c : nums)
    //         nums[abs(c) - 1] = -abs(
    //             nums[abs(c) - 1]);  // mark c is present by negating
    //             nums[c-1]
    //     for (int i = 0; i < size(nums); i++)
    //         if (nums[i] > 0) ans.push_back(i + 1);
    //     // nums[i] > 0 means i+1 isnt present in nums
    //     return ans;
    // }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 想法: 第一輪走訪把nums[i]換到第i格
        // 然後第二輪的時候去按nums[i] 跟 i 是不是對應的
        vector<int> ans;
        for (auto& c : nums)
            while (nums[c - 1] != c)
                swap(c, nums[c - 1]);  // swap till correct index place of c is
                                       // not occupied by c itself
        for (int i = 1; i <= nums.size(); i++)
            if (i != nums[i - 1]) ans.push_back(i);
        // correct index place of i is not occupied by i itself
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