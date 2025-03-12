#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int r, c;
vector<string> arr;
queue<pair<int, int>> fire_q;
queue<tuple<int, int, int>> jihun_q;
vector<vector<int>> fire_map;
vector<vector<bool>> visited;

void fire_process(){
    while(!fire_q.empty()){
        int size = fire_q.size();
        for(int i = 0;i < size;i++){
            auto[x, y] = fire_q.front(); fire_q.pop();
            for(int d = 0;d < 4;d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == '#') continue;
                if(fire_map[x][y] + 1 < fire_map[nx][ny]){
                    fire_map[nx][ny] = fire_map[x][y] + 1;
                    fire_q.push({nx, ny});
                }
            }
        }
    }
}

int jihun_process(){
    while(!jihun_q.empty()){
        auto[cnt, x, y] = jihun_q.front(); jihun_q.pop();
        if(x == 0 || x == r - 1 || y == 0 || y == c - 1) return cnt + 1;
        for(int d = 0;d < 4;d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(arr[nx][ny] == '#' || visited[nx][ny]) continue;
            if(cnt + 1 < fire_map[nx][ny]){
                visited[nx][ny] = true;
                jihun_q.push({cnt + 1, nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c;
    arr.assign(r, "");
    fire_map.assign(r, vector<int>(c, 1e9));
    visited.assign(r, vector<bool>(c, false));
    
    for(int i = 0;i < r;i++){
        cin >> arr[i];
        for(int j = 0;j < c;j++){
            if(arr[i][j] == 'J'){
                jihun_q.push({0, i, j});
                visited[i][j] = true;
            }
            if(arr[i][j] == 'F'){
                fire_q.push({i, j});
                fire_map[i][j] = 0;
            }
        }
    }
   
    fire_process();
    int ans = jihun_process();
    cout << (ans == -1 ? "IMPOSSIBLE" : to_string(ans)) << "\n";
    return 0;
}