#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, l, r, sum, days = 0;
bool flag = true;
vector<vector<int>> arr;
vector<vector<bool>> visited;
queue<tuple<int, int>> q;
vector<tuple<int, int>> v;

void bfs(int i, int j){
    q.push({i, j});
    v.clear();
    v.push_back({i, j});
    visited[i][j] = true;
    sum = arr[i][j];
    
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int d = 0;d < 4; d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if(abs(arr[nx][ny] - arr[x][y]) >= l && abs(arr[nx][ny] - arr[x][y]) <= r){
                visited[nx][ny] = true;
                q.push({nx, ny});
                v.push_back({nx, ny});
                sum += arr[nx][ny];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> l >> r;
    arr.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];

    while(flag){
        flag = false;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(!visited[i][j]){
                    bfs(i, j);
                }
                if(v.size() > 1){
                    flag = true;
                    for(auto &pos : v){
                        auto[x, y] = pos;
                        arr[x][y] = sum / v.size();
                    }
                }
            }
        }
        if(flag) days++;
        visited.assign(n, vector<bool>(n));
    }
    cout << days << "\n";
    return 0;
}