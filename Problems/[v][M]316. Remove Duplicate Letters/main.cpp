#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string removeDuplicateLetters(string s) {
        vector<int> m(26, 0), vis(26, 0);
        string result = "";

        for (auto c : s) m[c - 'a']++;
        for (auto c : s) {
            m[c - 'a']--;
            // 遇到同個字母時，如果該字母已經確定在result中，就不再處理
            // 因為會先放到res，就表示他的的字典續比較小，要先放，所以後面遇到的都是不可能放入的
            if (vis[c - 'a']) continue;
            // 如果最後一個字母，比現在的還大，而且該字母後面還有，表示可以先將其捨棄
            while (result.back() > c && m[result.back() - 'a'] > 0) {
                vis[result.back() - 'a'] = 0;
                result.pop_back();
            }
            result += c;
            vis[c - 'a'] = 1;
        }

        return result;
    }
};
int main() {
    cout << "[316. Remove Duplicate Letters]\n-----\n";

    // cout << Solution().removeDuplicateLetters("bcabc");
    cout << Solution().removeDuplicateLetters("cbacdcbc");

    return 0;
}