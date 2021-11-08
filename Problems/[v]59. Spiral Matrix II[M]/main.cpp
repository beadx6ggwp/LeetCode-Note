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
    vector<vector<int>> generateMatrix(int n) {
        int size = n * n;
        int left = 0, bot = 0, w = n, h = n;
        vector<Point> dirs = {Point(1, 0), Point(0, 1), Point(-1, 0),
                              Point(0, -1)};

        Point pos, tmp;
        int nowDir = 0, count = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (count <= size) {
            res[pos.y][pos.x] = count;

            tmp = pos + dirs[nowDir];
            // check next step is not over range
            if (tmp.x < left || tmp.x >= w || tmp.y < bot || tmp.y >= h ||
                res[tmp.y][tmp.x] != 0) {
                nowDir = (nowDir + 1) % dirs.size();
            }
            pos = pos + dirs[nowDir];
            count++;
        }
        return res;
    }
};

int main() {
    auto ans1 = Solution().generateMatrix(3);
    auto ans2 = Solution().generateMatrix(1);
    cout << "test";
    return 0;
}