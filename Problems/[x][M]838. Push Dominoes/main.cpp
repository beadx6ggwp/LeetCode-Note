#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    /*
    想法: 先從左往右掃過所有往右邊倒的，並記下倒幾個
    再從右往左，處理往左倒的
    */
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> cnt(n);
        // left to right
        for (int i = 1; i < n; i++) {
            if (dominoes[i - 1] == 'R' && dominoes[i] == '.') {
                dominoes[i] = 'R';
                cnt[i] = cnt[i - 1] + 1;
            }
        }
        // right to left
        // n = 8
        //              i
        // [0|1|2|3|4|5|6|7]
        for (int i = n - 2, now = 0; i >= 0; i--) {
            if (dominoes[i + 1] != 'L') continue;
            // 前一格是L
            now = cnt[i + 1] + 1;
            if (dominoes[i] == '.' || cnt[i] > now) {
                // . . . L
                // L L L L
                // 3 2 1 0

                // R R R L
                // R R L L
                // 0 1 2 0
                dominoes[i] = 'L';
                cnt[i] = now;
            } else if (dominoes[i] == 'R' && cnt[i] == now) {
                // 在R.M.L的中間，M的位置，雙方到M的累加值會一樣
                dominoes[i] = '.';
            }
        }

        return dominoes;
    }
};
int main() {
    cout << "[838. Push Dominoes]\n-----\n";

    auto o1 = Solution().pushDominoes(".L.R...LR..L..");

    return 0;
}