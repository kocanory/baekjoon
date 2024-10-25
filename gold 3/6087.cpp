#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int w, h, ans = 1e9;
vector<tuple<int, int>> c;
vector<string> arr;
vector<vector<vector<int>>> dp;

int bfs(){
    auto[sx, sy] = c[0];
    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, -1, 0});
    for(int i =0 ;i < 4;i++)
        dp[sx][sy][i] = 0;
        
    while(!q.empty()){
        auto[x, y, dir, cnt] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || arr[nx][ny] == '*') continue;
            if(dir == -1){
                dp[nx][ny][i] = cnt;
                q.push({nx, ny, i, cnt});
            }
            else{
                if(dir == i){
                    if(dp[nx][ny][i] > cnt){
                        dp[nx][ny][i] = cnt;
                        q.push({nx, ny, i, cnt});
                    }
                }
                else{
                    if(dp[nx][ny][i] > cnt + 1){
                        dp[nx][ny][i] = cnt + 1;
                        q.push({nx, ny, i, cnt + 1});
                    }
                }
            }
        }
    }
    auto[ex, ey] = c[1];
    for(int i = 0;i < 4;i++)
        ans = min(ans, dp[ex][ey][i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> w >> h;
    
    arr.assign(h, "");
    dp.assign(h, vector<vector<int>>(w, vector<int>(4, 1e9)));
    
    for(int i = 0;i < h;i++){
        cin >> arr[i];
        for(int j = 0;j < w;j++){
            if(arr[i][j] == 'C')
                c.push_back({i, j});
        }
    }

    cout << bfs() << "\n";
    return 0;
}