#include <bits/stdc++.h>
using namespace std;

// simple solution, 用bit來當hash
int solution(vector<int> in) {
    int n = in.size();

    int bit = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int val = in[i];
        m = max(m, val);
        bit = bit | (1 << val);
    }
    int mask = 1;
    for (int i = 1; i <= m; i++) {
        int v = bit & ((mask << i));
        if (v == 0) return i;
    }

    return -1;
}

int test(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        while (1) {
            int n = nums[i];
            if (n == -1 || nums[n - 1] == -1) break;

            nums[i] = nums[n - 1];
            nums[n - 1] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (nums[i] != -1) return i + 1;
    }

    return -1;
}
int firstMiss(vector<int>& nums) {
    int N = nums.size();
    // 每個n的家應該都要在nums[n-1]
    for (int i = 0; i < N; i++) {
        while (1) {
            int& n = nums[i];
            // 如果n這孤兒已經有家了，表示沒問題，下一位
            if (n == nums[n - 1]) break;

            // 把這個孤兒n送回家
            swap(n, nums[n - 1]);
            // 這時候的nums[i]，就會是新的孤兒，所以循環處理，直到都有家
            // 因為題目說長度是N，n的範圍是1~N，所以絕對有家
        }
    }

    // 抓出缺漏的第一個數字
    for (int i = 0; i < N; i++) {
        if (i + 1 != nums[i]) return i + 1;
    }

    return -1;
}
int firstMiss2(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++)
        while (nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);

    for (int i = 0; i < N; i++)
        if (i + 1 != nums[i]) return i + 1;

    return -1;
}
/*
e.g.
index: 0 1 2 3 4
  A = [4 2 1 2 5]

i = 0:
    n = A[0]:4
    A[n-1] => A[3]:2
    4 != 2, 表示4還沒有家, swap(n, A[n-1])

    swap後 A = [2 2 1 4 5]
               ^-----^

    n = A[0]:2
    A[n-1] => A[1]:2
    2 == 2, 2原本就有不用動，OK

i = 1:
    n = A[1]:2
    A[n-1] => A[1]:2
    2 == 2, OK

i = 2:
    n = A[2]:1
    A[n-1] => A[0]:2
    1!=2, 表示1沒回家, swap

    swap後 A = [1 2 2 4 5]
                ^---^
i = 3:
i = 4:
    n = A[i]
    A[i] = A[n-1] 本來就在家, 不用動

OK, 都處理好了, 大家都不是孤兒
index: 0 1 2 3 4
  A = [1 2 2 4 5]
  發現A[2]沒有對應, 所以就找到了3這個家沒人
  ans = 3
*/

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        // 每個n的家應該都要在nums[n-1]
        for (int i = 0; i < N; i++) {
            while (1) {
                int& n = nums[i];
                // 如果n這孤兒已經有家了，表示沒問題，下一位
                //  n > N 如果超出範圍就不管他
                if (n <= 0 || n > N || n == nums[n - 1]) break;

                // 把這個孤兒n送回家
                swap(n, nums[n - 1]);
                // 這時候的nums[i]，就會是新的孤兒，所以循環處理，直到都有家
                // 因為題目說長度是N，範圍是1~N，所以這些孤兒絕對有家
            }
        }

        // 抓出缺漏的第一個數字
        for (int i = 0; i < N; i++) {
            if (i != nums[i] - 1) return i + 1;
        }

        return N + 1;
    }
};

int firstMiss3(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) nums[nums[i] - 1] = nums[i];

    for (int i = 0; i < N; i++)
        if (i + 1 != nums[i]) return i + 1;

    return -1;
}
int main() {
    cout << "[]\n-----\n";
    vector<int> in = {5, 2, 1, 1, 2, 3, 5, 8};
    int ans = Solution().firstMissingPositive(in);
    cout << ans << '\n';
    return 0;
}