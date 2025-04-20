#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

int n, sx, sy, ex, ey;
vector<vector<int>> arr;

void bfs() {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    arr[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == ex && y == ey) break;
        for (int i = 0;i < 6;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != -1) continue;
            q.push({nx, ny});
            arr[nx][ny] = arr[x][y] + 1;
        }
    }
    cout << arr[ex][ey];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> sx >> sy >> ex >> ey;
    arr.assign(n, vector<int>(n, -1));

    bfs();
    return 0;
}