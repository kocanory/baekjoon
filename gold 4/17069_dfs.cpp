#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};

int n;
vector<vector<int>> arr;
vector<vector<vector<long long>>> dp;

bool check(int dir, int x, int y){
    if(dir == 0){
        int nx = x + dx[0], ny = y + dy[0];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) return false;
    }
    if(dir == 1){
        for(int i = 0;i < 3;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) return false;
        }
    }
    if(dir == 2){
        int nx = x + dx[2], ny = y + dy[2];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] != 0) return false;
    }
    return true;
}

long long dfs(int dir, int x, int y){
    if(x == n - 1 && y == n - 1) return 1;
    
    long long &res = dp[dir][x][y];
    if(res != -1) return res;
    res = 0;
    if(dir == 0){
        for(int i = 0;i <= 1;i++){
            if(check(i, x, y))
                res += dfs(i, x + dx[i], y + dy[i]);
        }
    }
    if(dir == 1){
        for(int i = 0;i <= 2;i++){
            if(check(i, x, y))
                res += dfs(i, x + dx[i], y + dy[i]);
        }
    }
    if(dir == 2){
        for(int i = 1;i <= 2;i++){
            if(check(i, x, y))
                res += dfs(i, x + dx[i], y + dy[i]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, vector<int>(n));
    dp.assign(3, vector<vector<long long>>(n, vector<long long>(n, -1)));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
            
    cout << dfs(0, 0, 1) << "\n";
    return 0;
}