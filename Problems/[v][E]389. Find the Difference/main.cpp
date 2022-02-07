#include <bits/stdc++.h>
using namespace std;
// 類似136 single number
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char cs : s) c ^= cs;
        for(char ct : t) c ^= ct;
        return c;
    }
};
int main() {
    cout << Solution().findTheDifference("abcd", "abcde") << "\n";
    // cout << Solution().findTheDifference("a", "aa") << "\n";
    return 0;
}