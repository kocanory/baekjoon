#include <iostream>
#include <vector>

using namespace std;

int n, ans;
vector<int> cur, res;
vector<bool> visited;

void dfs(int cnt, int now){
    if(cnt && !now && cnt - 1 > ans){
        ans = cnt - 1;
        res = cur;
        return;
    }
    for(int i = 0;i < n;i++){
        if((1 << i) & now){
            int k = (~(1 << i)) & now;
            if((cnt && !k) || !visited[k]){
                visited[k] = true;
                cur.push_back(i + 1);
                dfs(cnt + 1, k);
                cur.pop_back();
            }
        }
        if(!((1 << i) & now)){
            int k = (1 << i) | now;
            if(!visited[k]){
                visited[k] = true;
                cur.push_back(i + 1);
                dfs(cnt + 1, k);
                cur.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    visited.assign(1 << n, false);
    
    dfs(0, 0);
    cout << ans << "\n";
    for(auto &r : res) cout << r << "\n";
    return 0;
}