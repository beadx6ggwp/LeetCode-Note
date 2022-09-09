#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& arrs) {
        sort(arrs.begin(), arrs.end(), [](vector<int>& a, vector<int>& b) {
            // 如果atk不同，就先比atk，使攻擊由大->小
            if (a[0] != b[0]) return a[0] > b[0];
            // 否則將防禦由小排到大(keypoint)
            return a[1] < b[1];
        });
        int maxDef = 0, count = 0;
        for (size_t i = 0; i < arrs.size(); i++) {
            if (arrs[i][1] < maxDef) count++;
            maxDef = max(maxDef, arrs[i][1]);
        }

        return count;
    }
    int numberOfWeakCharacters2(vector<vector<int>>& properties) {
        int n = properties.size();
        int result = 0;

        // use greedy

        int maxAttack = 0;
        for (int i = 0; i < n; i++)
            maxAttack = max(maxAttack, properties[i][0]);

        // maxDefense[i]: max defense for attach value equal to one value
        vector<int> maxDefense(maxAttack + 1, 0);
        for (int i = 0; i < n; i++) {
            int atk = properties[i][0];
            int def = properties[i][1];
            maxDefense[atk] = max(maxDefense[atk], def);
        }
        // max defense for attack value >= i
        for (int i = maxAttack - 1; i >= 0; i--) {
            // max defense come from items with higher attack!
            maxDefense[i] = max(maxDefense[i], maxDefense[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            if (properties[i][0] != maxAttack &&
                properties[i][1] < maxDefense[properties[i][0] + 1])
                result++;
        }

        return result;
    }
};
int main() {
    cout << "[1996. The Number of Weak Characters in the Game]\n-----\n";
    vector<vector<int>> in0 = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<vector<int>> in1 = {{5, 5}, {6, 3}, {3, 6}};
    vector<vector<int>> in2 = {{2, 2}, {3, 3}};
    vector<vector<int>> in3 = {{1, 5}, {10, 4}, {4, 3}};

    int out0 = Solution().numberOfWeakCharacters2(in0);
    int out1 = Solution().numberOfWeakCharacters2(in1);
    int out2 = Solution().numberOfWeakCharacters2(in2);
    int out3 = Solution().numberOfWeakCharacters2(in3);

    return 0;
}