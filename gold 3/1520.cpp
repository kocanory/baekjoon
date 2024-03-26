#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> arr, dp;

int dfs(int x, int y){
    if(x == n - 1 && y == m - 1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(arr[x][y] > arr[nx][ny]) dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    arr.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));
    
    for(int i =0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];

    cout << dfs(0, 0) << "\n";
    return 0;
}