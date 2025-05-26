#include <iostream>
#include <vector>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k, ans = -1e9;
vector<vector<int>> arr;
vector<vector<bool>> check;

void dfs(int x, int y, int sum, int cnt){
    if(cnt == k){
        ans = max(ans, sum);
        return;
    }
    
    for(int i = x;i < n;i++){
        for(int j = i == x ? y : 0;j < m;j++){
            if(check[i][j]) continue;
            
            bool flag = true;
            for(int d = 0;d < 4;d++){
                int nx = i + dx[d], ny = j + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(check[nx][ny]){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                check[i][j] = true;
                dfs(i, j, sum + arr[i][j], cnt + 1);
                check[i][j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    arr.assign(n, vector<int>(m));
    check.assign(n, vector<bool>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
    dfs(0, 0, 0, 0);
    cout << ans;
    return 0;
}