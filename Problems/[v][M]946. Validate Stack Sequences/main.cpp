#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        for (auto n : pushed) {
            st.push(n);
            while (!st.empty() && st.top() == popped[i]) {
                st.pop();
                i++;
            }
        }

        return st.empty();
    }
    // O(1) space
    bool validateStackSequences2(vector<int>& pushed, vector<int>& popped) {
        int st = 0, now = 0;
        for (int x : pushed) {
            pushed[st++] = x;
            while (st > 0 && pushed[st - 1] == popped[now]) --st, ++now;
        }
        return st == 0;
    }
};
int main() {
    cout << "[]\n-----\n";
    vector<int> push1 = {1, 2, 3, 4, 5};
    vector<int> pop1 = {4, 5, 3, 2, 1};
    cout << Solution().validateStackSequences(push1, pop1) << "\n";
    return 0;
}