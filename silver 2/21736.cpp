#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m, ans = 0;
vector<string> arr;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (arr[x][y] == 'P') ans++;
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || arr[nx][ny] == 'X') continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'I') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    bfs();
    cout << (ans == 0 ? "TT" : to_string(ans)) << "\n";
}