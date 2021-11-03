#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x = 0, y = 0;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};
int orangesRotting(vector<vector<int>> &grid) {
    int h = grid.size(), w = grid[0].size();
    int good = 0;

    queue<Point> q;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (grid[y][x] == 1) good++;
            if (grid[y][x] == 2) q.push(Point(x, y));
        }
    }

    int times = 0;
    vector<Point> dir = {Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
    while (!q.empty()) {
        int todayCount = q.size();
        for (int i = 0; i < todayCount; i++) {
            Point cur = q.front(), newDir;
            q.pop();
            for (auto d : dir) {
                int nx = cur.x + d.x;
                int ny = cur.y + d.y;
                if (nx >= 0 && nx < w && ny >= 0 && ny < h &&
                    grid[ny][nx] == 1) {
                    grid[ny][nx] = 2;
                    q.push(Point(nx, ny));
                    good--;
                }
            }
        }
        times++;
    }
    // 需要的是經過幾分鐘，所以times-1來去掉初始的第一分鐘
    return (good > 0) ? -1 : (times > 0 ? times - 1 : 0);
}

vector<vector<int>> arr1{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
vector<vector<int>> arr2{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
vector<vector<int>> arr3{{0, 2}};
int main() {
    int num;
    cout << orangesRotting(arr3) << "\n";
    return 0;
}