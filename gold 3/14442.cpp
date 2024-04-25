#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k;
vector<vector<vector<bool>>> visited;
vector<vector<int>> map;

void bfs(){
    bool check = true;
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;
    
    while(!q.empty()){
        auto[x, y, count, wall] = q.front(); q.pop();
        if(x == n - 1 && y == m - 1){
            cout << count << "\n";
            return;
        }
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 0 && !visited[wall][nx][ny]){
                visited[wall][nx][ny] = true;
                q.push({nx, ny, count + 1, wall});
            }
            if(map[nx][ny] == 1 && wall < k && !visited[wall + 1][nx][ny]){
                visited[wall + 1][nx][ny] = true;
                q.push({nx, ny, count + 1, wall + 1});                
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    map.assign(n, vector<int>(m));
    visited.assign(k + 1, vector<vector<bool>>(n, vector<bool>(m, false)));
    
    for(int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j < m;j++){
            map[i][j] = s[j] - '0';
        }
    }
    bfs();
    return 0;
}