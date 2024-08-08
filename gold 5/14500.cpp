#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ans = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;

void dfs(int x, int y, int count, int sum) {
    if(count == 4) {
        ans = max(ans, sum);
        return;
    }
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
        visited[nx][ny] = true;
        dfs(nx, ny, count + 1, sum + arr[nx][ny]);
        visited[nx][ny] = false;
    }
}

void T_check(int x, int y) {
    for(int i = 0;i < 4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(i % 2) {
            if(nx - 1 < 0 || nx + 1 >= n) continue;
            ans = max(ans, arr[x][y] + arr[nx][ny] + arr[nx - 1][ny] + arr[nx + 1][ny]);
        }else {
            if(ny - 1 < 0 || ny + 1 >= m) continue;
            ans = max(ans, arr[x][y] + arr[nx][ny] + arr[nx][ny - 1] + arr[nx][ny + 1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m));

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++) {
            visited[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            T_check(i, j);
            visited[i][j] = false;
        }
    cout << ans << "\n";
    return 0;
}