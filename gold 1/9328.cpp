#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include <cstring>

using namespace std;

int t, n, m, answer = 0;
string key;
vector<string> arr;
vector<vector<bool>> visited;
list<tuple<int, int>> door;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int sx, int sy){
    queue<tuple<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int d = 0;d < 4;d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= n + 2 || ny < 0 || ny >= m + 2) continue;
            if(arr[nx][ny] == '*') continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if(isupper(arr[nx][ny])){
                if(key.find(tolower(arr[nx][ny])) == string::npos){
                    door.push_back({nx, ny});
                    continue;
                }
            }
            if(islower(arr[nx][ny])){
                if(key.find(arr[nx][ny]) == string::npos)
                    key += arr[nx][ny];
            }
            if(arr[nx][ny] == '$') answer++;
            q.push({nx, ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    
    while(t--){
        answer = 0;
        cin >> n >> m;
        visited.assign(n + 2, vector<bool>(m + 2, false));
        arr.assign(n + 2, "");
        for(int i = 1;i <= n;i++) {
            cin >> arr[i];
            arr[i] = '.' + arr[i] + '.';
        }
        arr[0].assign(m + 2, '.');
        arr[n + 1].assign(m + 2, '.');
        
        cin >> key;
        if(key == "0") key = "";

        queue<tuple<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            auto[x, y] = q.front(); q.pop();
            bfs(x, y);
            int len = key.length();

            for(int i = 0;i < len;i++){
                for(auto iter = door.begin();iter != door.end();iter++){
                    auto[door_x, door_y] = *iter;
                    if(key[i] == tolower(arr[door_x][door_y])){
                        q.push({door_x, door_y});
                        iter = door.erase(iter);
                        iter--;
                    }
                }
            }
        }

        cout << answer << '\n';
        door.clear();
        key.clear();
    }
    return 0;
}