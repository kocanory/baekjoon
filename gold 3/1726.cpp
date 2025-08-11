#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int m, n;
int arr[100][100];
int check[5][100][100];
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
tuple<int, int, int> s, e;
queue<tuple<int, int, int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n;
    
    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    auto &[sx, sy, sd] = s;
    cin >> sx >> sy >> sd;
    
    auto &[ex, ey, ed] = e;
    cin >> ex >> ey >> ed;
    
    q.push({0, sx - 1, sy - 1, sd});
    check[sd][sx - 1][sy - 1] = true;
    
    while(!q.empty()){
        auto[cnt, x, y, d] = q.front(); q.pop();
        if(make_tuple(x + 1, y + 1, d) == e){
            cout << cnt;
            break;
        }
        
        if(d <= 2){
            for(int i = 3;i <= 4;i++)
                if(!check[i][x][y]){
                    q.push({cnt + 1, x, y, i});
                    check[i][x][y] = true;
                }
        }
        else{
            for(int i = 1;i <= 2;i++)
                if(!check[i][x][y]){
                    q.push({cnt + 1, x, y, i});
                    check[i][x][y] = true;
                }
        }
        
        for(int i = 1;i <= 3;i++){
            int nx = x + dx[d] * i, ny = y + dy[d] * i;
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) break;
            if(arr[nx][ny] == 1) break;
            if(!check[d][nx][ny]){
                check[d][nx][ny] = true;
                q.push({cnt + 1, nx, ny, d});
            }
        }
    }
    return 0;
}