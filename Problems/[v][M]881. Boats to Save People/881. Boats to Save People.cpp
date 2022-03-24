#include <bits/stdc++.h>
using namespace std;
// https://stackoverflow.com/questions/18045208/override-mapcompare-with-lambda-function-directly
class Solution {
   public:
    int numRescueBoats2(vector<int>& people, int limit) {
        // TLE
        int res = 0;
        auto m =
            std::map<int, int, std::function<bool(const int&, const int&)>>{
                [](const int& a, const int& b) { return a > b; }};
        for (auto w : people) m[w]++;
        int times = people.size();
        int totalCount = 0;

        while (times > 0) {
            int now = 0, catchPeople = 0;
            for (auto& t : m) {
                int w = t.first, c = t.second;
                while (catchPeople < 2 && now + w <= limit && t.second > 0) {
                    now += w;
                    t.second--;
                    times--;
                    catchPeople++;
                }
            }
            totalCount++;
        }

        return totalCount;
    }
    int numRescueBoats3(vector<int>& people, int limit) {
        int times = people.size();
        int totalCount = 0;

        int nowI = 0, now = 0;
        while (times > 0) {
            if (now + people[nowI] <= limit) {
                now += people[nowI];
                nowI++;
                times--;
            } else {
                totalCount++;
                now = 0;
            }
        }
        return totalCount + 1;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int ans = 0;

        while (left <= right) {
            //因為limit一定>people[right]，所以每次至少會載走一個right，那就再看能不能多載一個
            ans++;
            if (people[left] + people[right] <= limit) left++;
            right--;
        }

        return ans;
    }
};
int main() {
    cout << "[881. Boats to Save People]\n-----\n";
    //
    //     vector<int> in1 = {1, 2};
    //     cout << Solution().numRescueBoats(in1, 3) << "\n";
    //
    //     vector<int> in2 = {3, 2, 2, 1};
    //     cout << Solution().numRescueBoats(in2, 3) << "\n";
    //
    //     vector<int> in3 = {3, 5, 3, 4};
    //     cout << Solution().numRescueBoats(in3, 5) << "\n";
    //
    //     vector<int> in4 = {3, 2, 3, 2, 2};
    //     cout << Solution().numRescueBoats(in4, 6) << "\n";
    vector<int> in5 = {3, 8, 7, 1, 4};
    cout << Solution().numRescueBoats(in5, 9) << "\n";
    //  at most two people
    // [3,8,7,1,4], 9 => 3
    //[3,2,3,2,2], 6 => 3 (3,2)+(3,2)+(2), not (3,3)+(2,2,2)
    return 0;
}