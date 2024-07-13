#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<string> arr;

bool dfs(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(arr[x][y] == 'x') return false;
    if(y == m - 1) return true;
    arr[x][y] = 'x';
    return dfs(x - 1, y + 1) || dfs(x, y + 1) || dfs(x + 1, y + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < n;i++)
        if(dfs(i, 0))
            ans++;
    cout << ans << "\n";
    return 0;
}