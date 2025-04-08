#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int r, c, sheep = 0, wolf = 0;
vector<string> arr;
vector<vector<bool>> visited;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    int s_cnt = 0, w_cnt = 0;

    while (!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        if (arr[x][y] == 'o') s_cnt++;
        else if (arr[x][y] == 'v') w_cnt++;

        for (int d = 0;d < 4;d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || arr[nx][ny] == '#') continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    if (s_cnt > w_cnt) sheep += s_cnt;
    else wolf += w_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    arr.assign(r, "");
    visited.assign(r, vector<bool>(c));

    for (int i = 0;i < r;i++) cin >> arr[i];

    for (int i = 0;i < r;i++)
        for (int j = 0;j < c;j++)
            if (arr[i][j] != '#' && !visited[i][j])
                bfs(i, j);

    cout << sheep << " " << wolf;
    return 0;
}