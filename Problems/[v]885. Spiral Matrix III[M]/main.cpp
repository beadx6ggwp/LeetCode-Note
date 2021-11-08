#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x = 0, y = 0;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
};
class Solution {
   public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int left = 0, bot = 0, w = cols, h = rows;
        int size = w * h;

        Point pos(cStart, rStart), tmp;
        int nowDir = 0, count = 1, walk = 1;
        vector<Point> dirs = {Point(1, 0), Point(0, 1), Point(-1, 0),
                              Point(0, -1)};

        vector<vector<int>> ans;

        ans.push_back({pos.y, pos.x});
        count++;
        while (count <= size) {
            int t = ceil(walk / 2.0);// step is :1 1 2 2 3 3 4 4 5 5...
            for (int i = 0; i < t; i++) {
                pos = pos + dirs[nowDir];
                if (pos.x >= left && pos.x < w && pos.y >= bot && pos.y < h) {
                    ans.push_back({pos.y, pos.x});
                    count++;
                }
            }
            walk++;
            nowDir = (nowDir + 1) % dirs.size();
        }

        return ans;
    }
};

int main() {
    // similar with 54 and 59
    auto ans2 = Solution().spiralMatrixIII(5, 6, 1, 4);
    auto ans1 = Solution().spiralMatrixIII(1, 4, 0, 0);
    return 0;
}