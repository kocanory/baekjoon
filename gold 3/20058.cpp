#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, q, ans_sum = 0, ans_size = 0;
vector<vector<int>> arr, check;
vector<int> cmd;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void turn(int x, int y, int l){
    for(int num = 0;num < l / 2;num++){
        int sx = x + num, sy = y + num, ex = x + l - 1 - num, ey = y + l - 1 - num, y_idx = sy, x_idx = ex, idx = 0;
        vector<int> tmp;
        for(int i = sx;i < ex;i++) tmp.push_back(arr[i][sy]);
        for(int i = sx;i < ex;i++) arr[i][sy] = arr[ex][y_idx++];
        for(int j = sy;j < ey;j++) arr[ex][j] = arr[x_idx--][ey];
        for(int i = ex;i > sx;i--) arr[i][ey] = arr[sx][y_idx--];
        for(int j = ey;j > sy;j--) arr[sx][j] = tmp[idx++];
    }
}

void remake(int l){
    for(int i = 0;i <n;i+=l)
        for(int j = 0;j < n;j+=l)
            turn(i, j, l);
}

void melt(){
    vector<pair<int, int>> tmp;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++){
            if(!arr[i][j]) continue;
            int cnt = 0;
            for(auto [dx, dy] : dir){
                int nx = i + dx, ny = j + dy;
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || !arr[nx][ny]) continue;
                cnt++;
            }
            if(cnt < 3) tmp.push_back({i, j});
        }
    for(auto [i, j] : tmp){
        arr[i][j]--;
        ans_sum--;
    }
}

int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    check[i][j] = 1;
    int cnt = 1;
    
    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(auto [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || !arr[nx][ny] || check[nx][ny]) continue;
            q.push({nx, ny});
            check[nx][ny] = 1;
            cnt++;
        }
    }
    return cnt;
}

void calc(){
    for(int i = 0;i <n;i++)
        for(int j = 0;j <n;j++)
            if(!check[i][j] && arr[i][j]){
                int size = bfs(i, j);
                ans_size = max(size, ans_size);
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> q;
    n = 1 << n;
    arr.assign(n, vector<int>(n));
    check.assign(n, vector<int>(n));
    cmd.assign(q, 0);
    
    for(int i = 0;i <n;i++)
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
            ans_sum += arr[i][j];
        }

    for(int i = 0;i < q;i++) cin >> cmd[i];
    
    for(auto c : cmd){
        int l = 1 << c;
        remake(l);
        melt();
    }
    calc();
    cout << ans_sum << "\n" << ans_size;
    return 0;
}