#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int bx, by, result = 0, sz = 2, eat_count = 0;
bool eat = false;

void bfs(int i, int j, int size){
    queue<tuple<int, int, int>> q;
    q.push({i, j, 0});
    visited[i][j] = true;
    int t;
    
    while(!q.empty()){
        auto[x, y, count] = q.front(); q.pop();
        
        if(arr[x][y] > 0 && arr[x][y] < size && t == count){
            if((bx > x) || (bx == x && by > y)){
                bx = x;
                by = y;
            }
        }
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if(arr[nx][ny] <= size){
                if(arr[nx][ny] > 0 && arr[nx][ny] < size && !eat){
                    eat = true;
                    bx = nx;
                    by = ny;
                    t = count + 1;
                    result += t;
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
    arr.resize(n, vector<int> (n));
    
    for(int i = 0;i < n;i++)
        for(int j =0;j < n;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                bx = i;
                by = j;
                arr[i][j] = 0;
            }
        }

    while(true){
        visited.assign(n, vector<bool> (n, false));
        bfs(bx, by, sz);
        if(eat){
            eat = false;
            eat_count++;
            arr[bx][by] = 0;
            if(eat_count == sz){
                sz++;
                eat_count = 0;
            }
        }
        else break;
    }
    cout << result << "\n";
    return 0;
}