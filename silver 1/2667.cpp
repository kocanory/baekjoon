#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
vector<string> arr;
vector<vector<bool>> visited;
vector<int> ans;

int bfs(int i, int j) {
    queue<tuple<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int cnt = 0;

    while (!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        cnt++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || arr[nx][ny] == '0') continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, "");
    visited.assign(n, vector<bool>(n));

    for (int i = 0;i <n;i++) cin >> arr[i];

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[i][j] == '1' && !visited[i][j])
                ans.push_back(bfs(i, j));
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto a : ans) cout << a << "\n";
    return 0;
}