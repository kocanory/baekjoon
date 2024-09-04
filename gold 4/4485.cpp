#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, count = 1;
vector<vector<int>> arr, drop;

int bfs(){
    queue<tuple<int, int>> q;
    q.push({0, 0});
    drop[0][0] = arr[0][0];

    while(!q.empty()){
        auto[x, y] = q.front(); q.pop();
        for(int i = 0;i <4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(drop[nx][ny] <= drop[x][y] + arr[nx][ny]) continue;
            drop[nx][ny] = drop[x][y] + arr[nx][ny];
            q.push({nx, ny});
        }
    }
    return drop[n - 1][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> n;
        if(!n) break;
        arr.assign(n, vector<int>(n));
        drop.assign(n, vector<int>(n, 1e9));

        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                cin >> arr[i][j];
        cout << "Problem " << count++ << ": " << bfs() << "\n";
    }
    return 0;
}