#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, cnt, wval = 0, bval = 0;
vector<string> arr;
vector<vector<bool>> check;

void dfs(int x, int y, char val){
    check[x][y] = true;
    cnt++;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= m || check[nx][ny] || arr[nx][ny] != val) continue;
        dfs(nx, ny, val);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(m, "");
    check.assign(m, vector<bool>(n));
    
    for(int i = 0;i <m;i++) cin >> arr[i];
    
    for(int i = 0;i <m;i++)
        for(int j = 0;j < n;j++)
            if(!check[i][j]){
                cnt = 0;
                dfs(i, j, arr[i][j]);
                if(arr[i][j] == 'W') wval += cnt * cnt;
                else bval += cnt * cnt;
            }
    cout << wval << " " << bval;
    return 0;
}