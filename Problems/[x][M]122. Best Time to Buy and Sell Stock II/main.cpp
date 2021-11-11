#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])  // yesterday was valley, today is peak
                profit += prices[i] - prices[i - 1];  // buy yesterday, sell today
        return profit;
    }
};

int main() {
    vector<int> in1 = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(in1);
    return 0;
}