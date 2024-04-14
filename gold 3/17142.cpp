#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, result = 1e9;
vector<vector<int>> arr, dp;
vector<tuple<int, int>> virus;
vector<int> virus_check;
queue<tuple<int, int>> q;

void bfs(){
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] != 1 && dp[nx][ny] == -1){
                dp[nx][ny] = dp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    bool flag = true;
    int Max = 0;
    for(int i = 0;i < n && flag;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] == 0){
                if(dp[i][j] == -1){
                    flag = false;
                    break;
                }
                Max = max(Max, dp[i][j]);
            }
        }
    }
    if(flag) result = min(Max, result);
}

void dfs(int index){
    if(virus_check.size() >= m){
        dp.assign(n, vector<int>(n, -1));
        for(auto v : virus_check)
        {
            auto[x, y] = virus[v];
            dp[x][y] = 0;
            q.push({x, y});
        }
        bfs();
        return;
    }
    for(int i = index;i < virus.size();i++){
        virus_check.push_back(i);
        dfs(i + 1);
        virus_check.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector<int>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    dfs(0);
    if(result == 1e9) result = -1;
    cout << result << "\n";
    return 0;
}
