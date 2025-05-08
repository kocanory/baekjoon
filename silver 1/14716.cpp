#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int n, m, ans = 0;
vector<vector<int>> arr;
vector<vector<bool>> check;

void dfs(int x, int y){
    check[x][y] = true;
    for(int i = 0;i < 8;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || !arr[nx][ny] || check[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    check.assign(n, vector<bool>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
            
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] && !check[i][j]){
                dfs(i, j);
                ans++;
            }
    
    cout << ans;
    return 0;
}