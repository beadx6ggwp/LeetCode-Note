#include <bits/stdc++.h>
using namespace std;
// 類似53. Maximum Subarray
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;

        for (int i=0; i<nums.size(); i++)
        {
            if (i%2==0)
            {
                a = max(a+nums[i], b);
            }
            else
            {
                b = max(a, b+nums[i]);
            }
        }

        return max(a, b);
    }
};
int main(){

    return 0;
}