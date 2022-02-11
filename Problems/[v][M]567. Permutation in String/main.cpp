#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int wsize = s1.size();
        vector<int> m1(26, 0), m2(26, 0);
        for (auto c : s1) m1[c - 'a']++;

        for (int i = 0; i < s2.size(); i++) {
            if (i >= wsize) {
                m2[s2[i - wsize] - 'a']--;
            }
            m2[s2[i] - 'a']++;
            if (m1 == m2) return true;
        }

        return false;
    }
};

int main() {
    cout << Solution().checkInclusion("ab", "eidbaooo") << "\n";
    cout << Solution().checkInclusion("ab", "eidboaoo") << "\n";
    return 0;
}