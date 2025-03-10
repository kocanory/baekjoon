#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
vector<string> arr;
vector<vector<int>> dp;

void bfs(){
    queue<tuple<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;

    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == '1'){
                if(dp[nx][ny] > dp[x][y]){
                    dp[nx][ny] = dp[x][y];
                    q.push({nx, ny});
                }
            }
            else{
                if(dp[nx][ny] > dp[x][y] + 1){
                    dp[nx][ny] = dp[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, "");
    dp.assign(n, vector<int>(n, 1e9));

    for(int i = 0;i < n;i++) cin >> arr[i];
    bfs();
    return 0;
}