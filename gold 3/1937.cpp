#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, result = 1;
vector<vector<int>> arr, dp;

int dfs(int x, int y){
    int d;
    for(d = 0;d < 4;d++){
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(arr[x][y] < arr[nx][ny]) break;
    }
    if(d >= 4) return dp[x][y] = 1;
    if(dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 1;
    int next = 0;
    for(d = 0;d < 4;d++){
        int nx = x + dx[d], ny = y + dy[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(arr[x][y] < arr[nx][ny]) next = max(next, dfs(nx, ny));
    }
    return dp[x][y] += next;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr.assign(n, vector<int>(n));
    dp.assign(n, vector<int>(n, -1));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            if(dp[i][j] == -1)
                result = max(result, dfs(i, j));
    
    cout << result << "\n";
    return 0;
}