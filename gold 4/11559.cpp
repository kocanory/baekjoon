#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int t = 0;
vector<string> arr(12);

bool bfs(int i, int j){
    queue<tuple<int, int>> q;
    vector<vector<bool>> visited(12, vector<bool>(6));
    vector<tuple<int, int>> v;
    q.push({i, j});
    v.push_back({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int d = 0;d < 4;d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6 || visited[nx][ny]) continue;
            if(arr[i][j] == arr[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                v.push_back({nx, ny});
            }
        }
    }
    if(v.size() >= 4){
        for(auto &a : v){
            auto[x, y] = a;
            arr[x][y] = '.';
        }
        return true;
    }
    return false;
}

void down(){
    for(int j = 0;j < 6;j++){
        queue<char> q;
        for(int i = 11;i >= 0;i--)
            if(arr[i][j] != '.')
                q.push(arr[i][j]);

        for(int i = 11;i >= 0;i--){
            if(!q.empty()){
                arr[i][j] = q.front();
                q.pop();
            }
            else arr[i][j] = '.';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0;i < 12;i++) cin >> arr[i];

    while(true){
        bool flag = false;
        for(int i = 0;i < 12;i++){
            for(int j = 0;j < 6;j++)
                if(arr[i][j] != '.' && bfs(i, j))
                    flag = true;
        }
        if(flag) {
            t++;
            down();
        }
        else{
            cout << t << "\n";
            break;
        }
    }
    return 0;
}