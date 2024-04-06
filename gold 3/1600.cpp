#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int horse_x[] = {2, 2, -1, 1, -2, -2, -1, 1};
int horse_y[] = {-1, 1, -2, -2, -1, 1, 2, 2}; 

int k, w, h;
vector<vector<int>> arr;
vector<vector<vector<bool>>> visited;

int bfs(){
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    
    while(!q.empty()){
        auto [x, y, horse, count] = q.front(); q.pop();
        if(x == h - 1 && y == w - 1) return count;
        if(horse < k){
            for(int i = 0;i < 8;i++){
                int nx = x + horse_x[i], ny = y + horse_y[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny][horse + 1] || arr[nx][ny]) continue;
                visited[nx][ny][horse + 1] = true;
                q.push({nx, ny, horse + 1, count + 1});
            }
        }
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny][horse] || arr[nx][ny]) continue;
            visited[nx][ny][horse] = true;
            q.push({nx, ny, horse, count + 1});
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> k;
    cin >> w >> h;
    arr.assign(h, vector<int>(w));
    visited.assign(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
    for(int i = 0;i < h;i++)
        for(int j =0;j < w;j++)
            cin >> arr[i][j];
    
    cout << bfs() << "\n";
    return 0;
}