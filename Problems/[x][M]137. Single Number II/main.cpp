#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {

        return 0;
    }
};

int main() {
    vector<int> in1 = {2, 2, 3, 2};
    vector<int> in2 = {0, 1, 0, 1, 0, 1, 99};

    cout << Solution().singleNumber(in1) << "\n";
    cout << Solution().singleNumber(in2) << "\n";
    return 0;
}