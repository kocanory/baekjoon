#include <iostream>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited;
int n, answer = INT_MAX;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int num){
    queue<tuple<int, int, int>> q;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] == num){
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
            if(arr[nx][ny] != 0 && arr[nx][ny] != num){
                answer = min(answer, cost);
                return;
            }
            if(visited[nx][ny]) continue;
            q.push({cost + 1, nx, ny});
            visited[nx][ny] = true;
        }
    }
}

void findLand(int x, int y, int label){
    queue<pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = label;
    
    while(!q.empty()){
        pair<int, int> now = q.front(); q.pop();
        
        for(int i = 0;i < 4;i++){
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == 0 || arr[nx][ny] == label) continue;
            
            q.push({nx, ny});
            arr[nx][ny] = label;
        }
    }
}

void solution(){
    int label = 2;
    for(int i = 0;i < n;i++){
        for(int j =0;j < n;j++){
            if(arr[i][j]){
                findLand(i, j, label);
                label++;
            }
        }
    }
    
    for(label;label >= 2;label--)
    {
        visited.resize(n, vector<bool>(n, false));
        bfs(label);
    }
    cout << answer;
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