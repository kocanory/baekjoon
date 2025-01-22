#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<string> arr;
vector<vector<bool>> visited;
queue<tuple<int, int, int>> q;

void bfs(){
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while(!q.empty()){
        auto[x, y, cnt] = q.front(); q.pop();
        if(x == n - 1 && y == m - 1){
            cout << cnt << "\n";
            return;
        }
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || arr[nx][ny] == '0') continue;
            q.push({nx, ny, cnt + 1});
            visited[nx][ny] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, "");
    visited.assign(n, vector<bool>(m));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    bfs();
    return 0;
}