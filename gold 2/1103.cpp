#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<string> arr;
vector<vector<int>> dp;
vector<vector<bool>> visited;

int dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == 'H') return 0;
    if(visited[x][y]){
        cout << -1 << "\n";
        exit(0);
    }
    if(dp[x][y] != -1) return dp[x][y];
    
    visited[x][y] = true;
    dp[x][y] = 0;
    for(int i = 0;i < 4;i++){
        int nx = x + (arr[x][y] - '0') * dx[i], ny = y + (arr[x][y] - '0') * dy[i];
        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    visited[x][y] = false;
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    arr.assign(n, "");
    dp.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<bool>(m));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    cout << dfs(0, 0) << "\n";

    return 0;
}