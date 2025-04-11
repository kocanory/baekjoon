#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, ans = 0, Max = 0, low;
vector<vector<int>> arr;
vector<vector<bool>> check;

void dfs(int x, int y){
    check[x][y] = true;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny] || arr[nx][ny] <= low) continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, vector<int>(n));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
            Max = max(Max, arr[i][j]);
        }

    for(low = 0;low < Max;low++){
        int cnt = 0;
        check.assign(n, vector<bool>(n));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                if(!check[i][j] && arr[i][j] > low){
                    dfs(i, j);
                    cnt++;
                }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}