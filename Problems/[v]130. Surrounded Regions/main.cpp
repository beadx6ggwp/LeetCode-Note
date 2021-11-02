#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>> &board) {
    int h = board.size();
    if (h == 0) return;
    int w = board[0].size();
    // auto dfs = [&](int x, int y) 兩者有差
    function<void(int, int)> dfs = [&](int x, int y) {
        if (x < 0 || x >= w || y < 0 || y >= h || board[y][x] != 'O') return;
        board[y][x] = 'K';
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    };
    for (int y = 0; y < h; y++) {
        dfs(0, y), dfs(w - 1, y);
    }
    for (int x = 0; x < w; x++) {
        dfs(x, 0), dfs(x, h - 1);
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (board[y][x] == 'O') {
                board[y][x] = 'X';
                continue;
            }
            if (board[y][x] == 'K') {
                board[y][x] = 'O';
                continue;
            }
        }
    }
}
vector<vector<char>> board1 = {{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
vector<vector<char>> board2 = {{'X', 'O', 'X', 'O', 'X', 'O'},
                               {'O', 'X', 'O', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'O', 'X', 'O'},
                               {'O', 'X', 'O', 'X', 'O', 'X'}};
int main() {
    cout << "Test:"
         << "\n";

    solve(board2);
    return 0;
}