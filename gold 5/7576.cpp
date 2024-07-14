#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, ans = 0;
vector<vector<int>> arr;
queue<tuple<int, int, int>> q;

bool check(){
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] == 0)
                return false;
    return true;
}

void bfs(){
    while(!q.empty()){
        auto[x, y, count] = q.front(); q.pop();
        ans = max(ans, count);
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n||ny < 0 || ny >= m || arr[nx][ny] != 0) continue;
            q.push({nx, ny, count + 1});
            arr[nx][ny] = 1;
        }
    }
    if(check()) cout << ans << "\n";
    else cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    arr.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({i, j, 0});
            }
        }
    bfs();
    return 0;
}