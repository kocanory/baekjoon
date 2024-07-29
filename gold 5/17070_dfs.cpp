#include <iostream>

using namespace std;

int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};
int n, ans;
int arr[16][16];

void dfs(int x, int y, int dir){
    if(x == n - 1 && y == n - 1 && !arr[x][y]){
        ans++;
        return;
    }
    for(int i = 0;i < 3;i++){
        if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= n || ny >= n || arr[nx][ny]) continue;
        if(i == 2 && (arr[nx - 1][ny] || arr[nx][ny - 1])) continue;
        dfs(nx, ny, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    dfs(0, 1, 0);
    cout << ans << "\n";
    return 0;
}