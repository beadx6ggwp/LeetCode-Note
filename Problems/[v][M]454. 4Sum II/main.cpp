#include <bits/stdc++.h>
using namespace std;
/* Philosophy

1. I know that Addtion have two parts in it  EG (a +b , Part 1 - a, Part 2- b.
2.So, Lets make and find this dependency factors. How can I do it?

3. If there are 4 Sum. it means 2 sums is going to Part 1 and another 2 gonna be Part 2 which are dependent on Part 1 for 0 resultant.

4. I gonna store summation 2 nums1 in a FREQUENCY Hashmap.

5. Then I traverse 2nd part of the summation (rest to nums) and keep checking that do (0-it1-it2) is exist in map . 

6. If yes, the add the frequency of Part1 int COUNT var.

7. return count;
*/
class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> mp;
        int count = 0, temp = 0;

        for (auto n1 : nums1) {
            for (auto n2 : nums2) {
                mp[n1 + n2]++;
            }
        }

        for (auto n3 : nums3) {
            for (auto n4 : nums4) {
                temp = -(n3 + n4);
                if (mp.count(temp)) {
                    count += mp[temp];
                }
            }
        }
        return count;
    }
};

int main() {
    auto in1a1 = vector<int>{1, 2}, in1a2 = vector<int>{-2, -1},
         in1a3 = vector<int>{-1, 2}, in1a4 = vector<int>{0, 2};

    cout << Solution().fourSumCount(in1a1, in1a2, in1a3, in1a4);

    return 0;
}