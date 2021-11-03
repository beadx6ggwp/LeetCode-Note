#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input1 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
vector<vector<int>> input2 = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};

int uniquePathsIII(vector<vector<int>> &grid) {
    int h = grid.size();
    int w = grid[0].size();

    int space = 1;// include start pos
    int sx, sy;
    int road = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (grid[y][x] == 1) {
                sx = x, sy = y;
            } else if (grid[y][x] == 0) {
                space++;
            }
        }
    }

    function<void(int, int, int)> dfs = [&](int x, int y, int step) {
        if (x < 0 || x >= w || y < 0 || y >= h || grid[y][x] == -1) return;
        if (grid[y][x] == 2) {
            if (space == step) road++;
            return;
        }
        grid[y][x] = -1;
        step++;
        dfs(x + 1, y, step);
        dfs(x - 1, y, step);
        dfs(x, y + 1, step);
        dfs(x, y - 1, step);
        grid[y][x] = 0;
    };
    dfs(sx, sy, 0);
    return road;
}

int main() {
    int ans = uniquePathsIII(input1);
    cout << "ans:" << ans;
    return 0;
}