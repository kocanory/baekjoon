#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int r, c, k, ans = 0;
vector<string> arr;
vector<vector<bool>> check;

void dfs(int x, int y, int cnt){
    if(cnt >= k){
        if(x == 0 && y == c - 1) ans++;
        return;
    }
    
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || arr[nx][ny] == 'T' || check[nx][ny]) continue;
        check[nx][ny] = true;
        dfs(nx, ny, cnt + 1);
        check[nx][ny] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c >> k;
    arr.assign(r, "");
    check.assign(r, vector<bool>(c));
    
    for(int i = 0;i < r;i++) cin >> arr[i];
    
    check[r - 1][0] = true;
    dfs(r - 1, 0, 1);
    
    cout << ans;

    return 0;
}