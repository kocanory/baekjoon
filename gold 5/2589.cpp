#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ans = 0;
vector<string> arr;
vector<vector<bool>> visited;

void bfs(int i, int j) {
    queue<tuple<int, int, int>> q;
    q.emplace(i, j, 0);
    visited[i][j] = true;

    while(!q.empty()) {
        auto[x, y, count] = q.front(); q.pop();
        ans = max(ans, count);
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 'W' || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.emplace(nx, ny, count + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    visited.assign(n, vector<bool>(m));

    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] == 'L') {
                bfs(i, j);
                visited.assign(n, vector<bool>(m));
            }

    cout << ans << "\n";
}