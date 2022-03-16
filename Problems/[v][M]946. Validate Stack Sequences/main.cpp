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
};
int main() {
    cout << "[]\n-----\n";
    vector<int> push1 = {1, 2, 3, 4, 5};
    vector<int> pop1 = {4, 5, 3, 2, 1};
    cout << Solution().validateStackSequences(push1, pop1) << "\n";
    return 0;
}