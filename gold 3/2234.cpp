#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int n, m, cnt, bigger, Max;
vector<vector<int>> arr;
vector<vector<bool>> visited;

int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    
    visited[i][j] = true;
    int s = 0;
    
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        s++;
        for(int d = 0;d < 4;d++){
            if((arr[x][y] & (1 << d)) != (1 << d)){
                int nx = x + dx[d], ny = y + dy[d];
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    arr.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m));
    
    for(int i = 0;i <n;i++)
        for(int j = 0;j <m;j++)
            cin >> arr[i][j];
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(!visited[i][j]){
                cnt++;
                bigger = max(bigger, bfs(i, j));
            }
    
    for(int i = 0;i <n;i++)
        for(int j = 0;j < m;j++)
            for(int d = 0;d < 4;d++)
                if((arr[i][j] & (1 << d)) == (1 << d)){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    visited.assign(n, vector<bool>(m));
                    arr[i][j] ^= (1 << d);
                    Max = max(Max, bfs(i, j));
                    arr[i][j] ^= (1 << d);
                }
    cout << cnt << "\n" << bigger << "\n" << Max;
    return 0;
}