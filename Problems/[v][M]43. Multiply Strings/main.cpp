#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        string res = "";
        vector<char> ans(len1 + len2, 0);
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                /*
                     next:i+j, curr:i+j+1
                                   n c
                      ________________
                      ind:     0 1 2 3
                        j:     1 2 3 4
                      ind:         0 1
                        i:         5 6
                        ______________
                      ind: 0 1 2 3 4 5
                        a: 0 0 0 0 0 0
                */
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + ans[i + j + 1];
                ans[i + j] += sum / 10;
                ans[i + j + 1] = sum % 10;  // carry
            }
        }
        // find first value to append answer
        for (auto n : ans) {
            if (res.size() || n) res += (char)(n + '0');
        }
        // ans is 0
        if (!res.size()) res = "0";

        return res;
    }
};
int main() {
    cout << Solution().multiply("123", "40");

    return 0;
}
