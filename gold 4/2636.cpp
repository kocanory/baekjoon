#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, t = 0, back = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;

bool bfs(){
    queue<tuple<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    int cnt = 0;
    t++;
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if(arr[nx][ny]){
                arr[nx][ny] = 0;
                cnt++;
            }
            else q.push({nx, ny});
        }
    }
    if(cnt){
        back = cnt;
        return false;
    }
    else{
        cout << t - 1 << "\n" << back << "\n";
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m));

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];

    while(!bfs()){
        visited.assign(n, vector<bool>(m));
    }
    return 0;
}