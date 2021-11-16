#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/daily-temperatures/discuss/1574806/C++-EASY-standard-sol-oror-INTUITIVE-approach-with-DRY-RUN-oror-STACK-appraoch
// https://medium.com/tomsnote/leetcode-739-daily-temperatures-70e003af6116
/*
Brute-Force: TLE
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int len = temps.size();
        vector<int> ans(len, 0);
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len && !ans[i]; j++) {
                if (temps[i] < temps[j]) ans[i] = j-i;
            }
        }
        return ans;
    }
};
*/
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int len = temps.size();
        vector<int> ans(len, 0);
        
        return ans;
    }
};

int main() {
    vector<int> in1 = {73, 74, 75, 71, 69, 72, 76, 73};
    //  [1,1,4,2,1,1,0,0]
    vector<int> in2 = {30, 40, 50, 60};
    // [1,1,1,0]
    vector<int> in3 = {30, 60, 90};
    // [1,1,0]
    auto ans1 = Solution().dailyTemperatures(in1);
    auto ans2 = Solution().dailyTemperatures(in2);
    auto ans3 = Solution().dailyTemperatures(in3);
    cout << "123"
         << "\n";
    return 0;
}