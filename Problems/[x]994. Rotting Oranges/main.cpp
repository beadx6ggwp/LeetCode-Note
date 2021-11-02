#include <bits/stdc++.h>
using namespace std;

struct cell {
    int x = 0, y = 0;
    cell(int _x, int _y) : x(_x), y(_y) {}
};
int orangesRotting(vector<vector<int>>& grid) {
    int w = grid.size(), h = grid[0].size();
    int fresh = 0;

    queue<cell> q;

    for (int r = 0; r < w; r++) {
        for (int c = 0; c < h; c++) {
            if (grid[r][c] == 1)
                fresh++;
            else if (grid[r][c] == 2)
                q.push(cell(r, c));
        }
    }
    while (!q.empty()) {
        
    }
    return 0;
}

int main() {
    int num;
    vector<vector<int>> arr1{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(arr1) << "\n";
    return 0;
}