#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<string> arr;
vector<vector<int>> visited[2];
int n, m;

void bfs(){
    queue<tuple<int, int, int>> q;
    visited[0][0][0] = 0;
    q.push({0, 0, 0});
    
    while(!q.empty()){
        auto[x, y, smash] = q.front(); q.pop();
        
        if((x == n - 1) && (y == m - 1)){
            cout << visited[smash][x][y] + 1 << "\n";
            return;
        }
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == '0' && visited[smash][nx][ny] == -1){
                visited[smash][nx][ny] = visited[smash][x][y] + 1;
                q.push({nx, ny, smash});
            }
            if(arr[nx][ny] == '1' && smash == 0 && visited[1][nx][ny] == -1) {
                visited[1][nx][ny] = visited[smash][x][y] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    arr.resize(n);
    
    for(int i = 0;i < 2;i++)
        visited[i].resize(n, vector<int>(m, -1));
    
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    bfs();
    return 0;
}