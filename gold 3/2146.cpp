#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> arr;
vector<vector<bool>> visited;
int n, answer = INT_MAX;

void findIsland(int i, int j, int label){
    queue<tuple<int, int>> q;
    q.push({i, j});
    arr[i][j] = label;
    
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == 0 || arr[nx][ny] == label) continue;
            arr[nx][ny] = label;
            q.push({nx, ny});
        }
    }
}

void bfs(int label){
    queue<tuple<int, int, int>> q;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] == label){
                visited[i][j] = true;
                q.push({0, i, j});
            }
        }
    }
    
    while(!q.empty()){
        auto[cost, x, y] = q.front(); q.pop();
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] != 0 && arr[nx][ny] != label){
                answer = min(answer, cost);
                return;
            }
            if(visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({cost + 1, nx, ny});
        }
    }
}

void solution(){
    int label = 2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] == 1){
                findIsland(i, j, label);
                label++;
            }
        }
    }
    
    for(label;label >= 2;label--){
        visited.resize(n, vector<bool> (n, false));
        bfs(label);
    }
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr.resize(n, vector<int>(n));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    solution();
    return 0;
}