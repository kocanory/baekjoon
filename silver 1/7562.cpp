#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int t, n, sx, sy, ex, ey;
vector<vector<int>> dp;

void bfs(){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if(x == ex && y == ey) break;
        
        for(int i = 0;i < 8;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || dp[nx][ny]) continue;
            dp[nx][ny] = dp[x][y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dp[ex][ey] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> n >> sx >> sy >> ex >> ey;
        dp.assign(n, vector<int>(n));
        bfs();
    }
    return 0;
}