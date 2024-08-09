#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ans = 0;
vector<string> arr;
vector<bool> visited(26);

void dfs(int x, int y, int count) {
    visited[arr[x][y] - 'A'] = true;
    for(int i = 0;i < 4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[arr[nx][ny] - 'A']) continue;
        dfs(nx, ny, count + 1);
    }
    ans = max(ans, count);
    visited[arr[x][y] - 'A'] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    for(int i = 0;i < n;i++) cin >> arr[i];
    dfs(0, 0, 1);
    cout << ans << "\n";
    return 0;
}