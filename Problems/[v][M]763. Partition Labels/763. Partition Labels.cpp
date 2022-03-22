#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) m[s[i]] = i;

        int start = 0, last = 0;
        for (int i = 0; i < s.size(); i++) {
            // 更新S0~Si字串最後出現的位置，如果last = i，表示從i之後都是新的
            last = max(last, m[s[i]]);

            if (last == i) {
                // 取個分割字串長度
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
int main() {
    cout << "[]\n-----\n";
    // auto out1 = Solution().partitionLabels("ababcbacadefegdehijhklij");
    auto out2 = Solution().partitionLabels("eccbbbbdec");
    return 0;
}