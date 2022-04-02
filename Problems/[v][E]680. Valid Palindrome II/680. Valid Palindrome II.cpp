#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalin(s, left + 1, right) ||
                       isPalin(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalin(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
int main() {
    cout << "[680. Valid Palindrome II]\n-----\n";
    cout << Solution().validPalindrome("aba") << "\n";
    cout << Solution().validPalindrome("abca") << "\n";
    cout << Solution().validPalindrome("abc") << "\n";
    return 0;
}