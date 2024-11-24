#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
vector<vector<int>> arr;
vector<bool> visited;

void dfs(int now){
    if(now == n){
        int st = 0, lin = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++){
                if(visited[i] && visited[j]) st += arr[i][j];
                if(!visited[i] && !visited[j]) lin += arr[i][j];
            }
        ans = min(ans, abs(st - lin));
        return;
    }
    for(int i = now;i <= n;i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> arr[i][j];
    dfs(1);
    cout << ans << "\n";
    return 0;
}