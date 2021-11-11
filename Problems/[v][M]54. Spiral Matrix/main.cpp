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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        int size = h * w;

        vector<Point> dirs = {Point(1, 0), Point(0, 1), Point(-1, 0),
                              Point(0, -1)};
        Point pos, tmp;
        int nowDir = 0;

        vector<int> res;
        while (size--) {
            res.push_back(matrix[pos.y][pos.x]);
            matrix[pos.y][pos.x] = 999;// visited

            tmp = pos + dirs[nowDir];
            // check next step is not over range or is visited
            if (tmp.x < 0 || tmp.x >= w || tmp.y < 0 || tmp.y >= h ||
                matrix[tmp.y][tmp.x] == 999) {
                nowDir = (nowDir + 1) % dirs.size();
            }
            pos = pos + dirs[nowDir];
        }
        return res;
    }
};

int main() {
    vector<vector<int>> input1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> input2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    auto ans1 = Solution().spiralOrder(input1);
    auto ans2 = Solution().spiralOrder(input2);
    cout << "test";
    return 0;
}