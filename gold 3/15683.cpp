#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, ans = 1e9;
vector<vector<int>> arr;
vector<tuple<int, int, int>> cctv;
vector<pair<int, int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void check(int x, int y, int d){
    d %= 4;
    while(true){
        int nx = x + dir[d].first, ny = y + dir[d].second;
        x = nx, y = ny;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6) return;
        if(arr[nx][ny] != 0) continue;
        arr[nx][ny] = -1;
    }
}

void dfs(int idx){
    if(idx == cctv.size()){
        int cnt = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(!arr[i][j])
                    cnt++;
        ans = min(ans, cnt);
        return;
    }
    
    auto[x, y, d] = cctv[idx];
    vector<vector<int>> tmp = arr;
    
    for(int i = 0;i < 4;i++){
        if(d == 1) check(x, y, i);
        else if(d == 2){
            check(x, y, i);
            check(x, y, i + 2);
        }
        else if(d == 3){
            check(x, y, i);
            check(x, y, i + 1);
        }
        else if(d == 4){
            check(x, y, i);
            check(x, y, i + 1);
            check(x, y, i + 2);
        }
        else{
            check(x, y, i);
            check(x, y, i + 1);
            check(x, y, i + 2);
            check(x, y, i + 3);
        }
        dfs(idx + 1);
        arr = tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] < 6)
                cctv.push_back({i, j, arr[i][j]});
        }
    dfs(0);
    cout << ans;
    return 0;
}