#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
vector<vector<int>> arr, c_arr;
vector<vector<bool>> visited;

int melt(int x, int y){
    int cnt = 0;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(arr[nx][ny] == 0) cnt++;
    }
    return cnt;
}

void bfs(int i, int j){
    queue<tuple<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if(arr[nx][ny] > 0){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void solve(){
    
    int year = 0;
    
    while(true){
        c_arr.assign(n, vector<int>(m));
        visited.assign(n, vector<bool>(m));
        int land_cnt = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(arr[i][j] && !visited[i][j]){
                    land_cnt++;
                    bfs(i, j);
                }
                
        if(land_cnt >= 2){
            cout << year << "\n";
            break;
        }
        if(land_cnt == 0){
            cout << 0 << "\n";
            break;
        }
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++){
                c_arr[i][j] = max(0, arr[i][j] - melt(i, j));
                
            }
        arr = c_arr;
        year++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
    solve();
    return 0;
}