#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dz[] = {0, 0, 0, 0, -1, 1};
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};

int n, m, h, ans = 0;
int arr[100][100][100];
queue<tuple<int, int, int, int>> q;

bool check(){
    for(int i = 0;i < h;i++)
        for(int j = 0;j < n;j++)
            for(int k = 0;k < m;k++)
                if(arr[i][j][k] == 0)
                    return false;
    return true;
}

void bfs(){
    while(!q.empty()){
        auto[z, x, y, count] = q.front(); q.pop();
        ans = max(ans, count);
        for(int i = 0;i < 6;i++){
            int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
            if(nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nz][nx][ny] != 0) continue;
            arr[nz][nx][ny] = 1;
            q.push({nz, nx, ny, count + 1});
        }
    }
    if(check()) cout << ans << "\n";
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    for(int i = 0;i < h;i++)
        for(int j = 0;j < n;j++)
            for(int k = 0;k < m;k++) {
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1)
                    q.push({i, j, k, 0});
            }
    bfs();
    return 0;
}