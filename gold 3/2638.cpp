#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, result = 0;
vector<vector<int>> arr;
queue<tuple<int, int>> q;

void dfs(int x, int y){
    if(arr[x][y] == 0) arr[x][y] = -1;
    else return;
    
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
    
    dfs(0, 0);
    while(true){
        for(int i =0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(arr[i][j] == 1){
                    int cnt = 0;
                    for(int k = 0;k < 4;k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(arr[nx][ny] == -1) cnt++;
                    }
                    if(cnt >= 2) q.push({i, j});
                }
            }
        }
        if(q.empty()) break;
        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            arr[x][y] = -1;
            for(int i =0;i < 4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(arr[nx][ny] == 0) dfs(nx, ny);
            }
        }
        result++;
    }
    cout << result << "\n";
    return 0;
}