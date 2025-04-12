#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ans = 0, cnt = 0, area;
vector<vector<int>> arr;
vector<vector<bool>> check;

void dfs(int x, int y){
    check[x][y] = true;
    area++;
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
    
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    check.assign(n, vector<bool>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
            
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] && !check[i][j]){
                cnt++;
                area = 0;
                dfs(i, j);
                ans = max(ans, area);
            }
    cout << cnt << "\n" << ans;
    return 0;
}