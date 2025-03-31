#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int m, n, k, cnt;
vector<vector<bool>> visited;
vector<int> ans;

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n >> k;
    visited.assign(m, vector<bool>(n));
    
    while(k--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1;i < y2;i++)
            for(int j = x1;j < x2;j++)
                visited[i][j] = true;
    }

    for(int i = 0;i < m;i++)
        for(int j = 0;j < n;j++)
            if(!visited[i][j]){
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
            
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto &a : ans) cout << a << " ";
    return 0;
}