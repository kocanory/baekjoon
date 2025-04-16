#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k, cnt, ans = 0;
vector<vector<bool>> arr, check;

void dfs(int x, int y){
    check[x][y] = true;
    cnt++;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || !arr[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    arr.assign(n, vector<bool>(m));
    check.assign(n, vector<bool>(m));
    
    while(k--){
        int x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = true;
    }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] && !check[i][j]){
                cnt = 0;
                dfs(i, j);
                ans = max(cnt, ans);
            }
    cout << ans;
    return 0;
}