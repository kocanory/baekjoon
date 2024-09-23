#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, 0, 0};
int dy[] = {0, -1, 1};

int n, m;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<vector<vector<int>>> dp;

int dfs(int x, int y, int dir){
    if(x == n - 1 && y == m - 1) return arr[x][y];
    if(dp[x][y][dir] != -1e9) return dp[x][y][dir];
    
    visited[x][y] = true;
    int bigger = -1e9;
    for(int i = 0;i < 3;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
        bigger = max(bigger, dfs(nx, ny, i));
    }
    visited[x][y] = false;
    return dp[x][y][dir] = arr[x][y] + bigger;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector(m, 0));
    visited.assign(n, vector(m, false));
    dp.assign(n, vector(m, vector<int>(3, -1e9)));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j <m;j++)
            cin >> arr[i][j];
    cout << dfs(0, 0, 0) << "\n";
    return 0;
}