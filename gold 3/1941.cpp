#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> arr(5);
vector<bool> check(25);
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int ans = 0;

bool four(){
    int cnt = 0;
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)
            if(check[i * 5 + j] && arr[i][j] == 'S')
                cnt++;
    return cnt >= 4;
}

bool adjacent(){
    queue<pair<int, int>> q;
    vector<bool> visited(25);
    
    for(int i = 0;i < 25;i++)
        if(check[i]){
            q.push({i / 5, i % 5});
            visited[i] = true;
            break;
        }
    int cnt = 1;
    
    while(!q.empty()){
        if(cnt == 7) break;
        auto[x, y] = q.front(); q.pop();
        for(auto [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5){
                int idx = nx * 5 + ny;
                if(check[idx] && !visited[idx]){
                    cnt++;
                    q.push({nx, ny});
                    visited[idx] = true;
                }
            }
        }
    }
    return cnt == 7;
}

void dfs(int idx, int cnt){
    if(cnt == 7){
        if(four() && adjacent())
            ans++;
        return;
    }
    for(int i = idx;i < 25;i++){
        check[i] = true;
        dfs(i + 1, cnt + 1);
        check[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0;i < 5;i++) cin >> arr[i];
    dfs(0, 0);
    cout << ans;

    return 0;
}