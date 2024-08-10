#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, k, l, dir = 1, cnt = 0, x = 0, y = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
queue<tuple<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n));

    cin >> k;
    for(int i = 0;i < k;i++){
        int a, b;
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
    }
    
    cin >> l;
    q.push({x, y});
    visited[x][y] = true;
    
    for(int i = 0;i < l;i++){
        int a;
        char b;
        cin >> a >> b;
        
        while(cnt < a || i == l - 1){
            cnt++;
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]){
                cout << cnt << "\n";
                return 0;
            }
            
            q.push({nx, ny});
            visited[nx][ny] = true;
            if(arr[nx][ny]){
                arr[nx][ny] = 0;
            }
            else{
                auto[tx, ty] = q.front(); q.pop();
                visited[tx][ty] = false;
            }
            if(cnt == a){
                if(b == 'D') dir = (dir + 1) % 4;
                else dir = (dir + 3) % 4;
            }
            x = nx;
            y = ny;
        }
    }
    return 0;
}