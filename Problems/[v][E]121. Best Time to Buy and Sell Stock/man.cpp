#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int ma = 0;
        for (auto n : prices) {
            // if(n<mi)mi=n;
            // if(n-mi>ma)ma = n-mi;
            mi = min(mi, n);
            ma = max(ma, n - mi);
        }
        return ma;
    }
};
int main() {
    vector<int> in1 = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(in1);
    return 0;
}