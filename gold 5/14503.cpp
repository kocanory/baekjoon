#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, m, r, c, d, ans;
vector<vector<int>> arr;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int sx, int sy, int sd){
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, sd});

    while(!q.empty()){
        auto[x, y, dir] = q.front(); q.pop();
        if(arr[x][y] == 0){
            arr[x][y] = -1;
            ans++;
        }
        bool uncleaned = false;

        int n_dir = dir;
        while(true){
            n_dir = (n_dir + 3) % 4;
            int nx = x + dx[n_dir], ny = y + dy[n_dir];
            if(arr[nx][ny] == 0){
                uncleaned = true;
                q.push({nx, ny, n_dir});
                break;
            }
            if(n_dir == dir) break;
        }
        if(!uncleaned){
            n_dir = (dir + 2) % 4;
            int nx = x + dx[n_dir], ny = y + dy[n_dir];
            if(arr[nx][ny] == 1) {
                cout << ans << "\n";
                return;
            }
            q.push({nx, ny, dir});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;
    arr.assign(n, vector<int>(m));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];

    bfs(r, c, d);
    return 0;
}