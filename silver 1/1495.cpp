#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, s, m, ans = -1;
vector<int> arr;
vector<vector<bool>> check;
queue<pair<int, int>> q;

void bfs(){
    q.push({0, s});
    check[s][0];
    
    while(!q.empty()){
        auto[cnt, now] = q.front(); q.pop();
        if(cnt == n){
            ans = max(ans, now);
            continue;
        }
        if(now + arr[cnt] <= m && !check[now + arr[cnt]][cnt + 1]){
            check[now + arr[cnt]][cnt + 1] = true;
            q.push({cnt + 1, now + arr[cnt]});
        }
        if(now - arr[cnt] >= 0 && !check[now - arr[cnt]][cnt + 1]){
            check[now - arr[cnt]][cnt + 1] = true;
            q.push({cnt+ 1, now - arr[cnt]});
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> s >> m;
    arr.assign(n, 0);
    check.assign(m + 1, vector<bool>(n + 1));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    bfs();

    return 0;
}