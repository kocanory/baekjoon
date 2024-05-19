#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, rx, ry, bx, by;
vector<string> arr;
bool visited[11][11][11][11];

void move(int &x, int &y, int &count, int dir){
    while(arr[x + dx[dir]][y + dy[dir]] != '#' && arr[x][y] != 'O'){
        x += dx[dir], y += dy[dir], count++;
    }
}

void bfs(){
    queue<tuple<int, int, int, int, int>> q;
    q.emplace(rx, ry, bx, by, 0);

    while(!q.empty()){
        auto[nrx, nry, nbx, nby, count] = q.front(); q.pop();
        if(count >= 10) break;
        for(int i = 0;i < 4;i++){
            int next_rx = nrx, next_ry = nry, next_bx = nbx, next_by = nby;
            int rc = 0, bc = 0;
            move(next_rx, next_ry, rc, i);
            move(next_bx, next_by, bc, i);

            if(arr[next_bx][next_by] == 'O') continue;
            if(arr[next_rx][next_ry] == 'O'){
                cout << count + 1 << "\n";
                return;
            }
            if(next_rx == next_bx && next_ry == next_by){
                if(rc > bc) next_rx -= dx[i], next_ry -= dy[i];
                else next_bx -= dx[i], next_by -= dy[i];
            }
            if(visited[next_rx][next_ry][next_bx][next_by]) continue;
            visited[next_rx][next_ry][next_bx][next_by] = true;
            q.emplace(next_rx, next_ry, next_bx, next_by, count + 1);
        }
    }
    cout << -1 << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 'R')
                rx = i, ry = j;
            if(arr[i][j] == 'B')
                bx = i, by = j;
        }
    }
    bfs();
    return 0;
}
