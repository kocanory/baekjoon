#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, result = 0;
vector<vector<int>> arr;

void check(vector<vector<int>> vec){
    
    queue<tuple<int, int>> q;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(vec[i][j] == 2)
                q.push({i, j});
            
                
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vec[nx][ny] == 0) {
                q.push({nx, ny});
                vec[nx][ny] = 2;
            }
        }
    }
    
    int count = 0;
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(vec[i][j] == 0)
                count++;
    
    result = max(count, result);
}

void dfs(int now, int count){
    if(count == 3) 
    {
        check(arr);
        return;
    }
    
    for(int i = now;i < n * m;i++){
        int x = i / m, y = i % m;
        if(arr[x][y] == 0){
            arr[x][y] = 1;
            dfs(now + 1, count + 1);
            arr[x][y] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
            
    dfs(0, 0);
    cout << result << "\n";
    return 0;
}