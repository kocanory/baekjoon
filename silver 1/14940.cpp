#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
vector<vector<int>> arr, map;
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != -1) continue;
            if (arr[nx][ny] == 1) {
                q.push({nx, ny});
                map[nx][ny] = map[x][y] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    map.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                q.push({i, j});
                map[i][j] = 0;
            }
            if (arr[i][j] == 0) map[i][j] = 0;
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
}