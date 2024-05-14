#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int t, n, m, k, answer;
vector<vector<int>> arr;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y){
    queue<tuple<int, int>> q;
    q.push({x, y});
    arr[x][y] = 0;
    
    while(!q.empty()){
        auto[now_x, now_y] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = now_x + dx[i], ny = now_y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny]){
                arr[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
    answer++;
}

int main()
{
    
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        arr.assign(n, vector<int>(m));
        answer = 0;
        
        while(k--){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }
        
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(arr[i][j])
                    bfs(i, j);
                    
        cout << answer << "\n";
    }
    return 0;
}