#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> arr;
vector<vector<bool>> visited;
int n, sx, sy, result = 0, sz = 2, e_count = 0;
bool eat = false;

void bfs(int i, int j){
    queue<tuple<int, int, int>> q;
    q.push({i, j, 0});
    visited[i][j] = true;
    int move = -1;
    
    while(!q.empty()){
        auto[x, y, count] = q.front(); q.pop();
        
        if(eat && move < count) continue;
        
        if(arr[x][y] > 0 && arr[x][y] < sz && move == count){
            if((sx > x) || (sx == x && sy > y)){
                sx = x, sy = y;
            }
        }
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if(arr[nx][ny] <= sz){
                if(arr[nx][ny] > 0 && arr[nx][ny] < sz && !eat){
                    eat = true;
                    sx = nx, sy = ny;
                    move = count + 1;
                    result += move;
                }
                else{
                    q.push({nx, ny, count + 1});
                    visited[nx][ny] = true;
                }
            }
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    arr.assign(n, vector<int>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                arr[i][j] = 0;
                sx = i, sy = j;
            }
        }

    while(true){
        visited.assign(n, vector<bool>(n, false));
        bfs(sx, sy);
        if(eat){
            eat = false;
            arr[sx][sy] = 0;
            e_count++;
            if(e_count == sz){
                sz++;
                e_count = 0;
            }
        }
        else break;
    }
    cout << result << "\n";
    return 0;
}