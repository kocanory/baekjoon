#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> arr, check;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
queue<pair<int, int>> q;

void bfs(){
    q.push({0, 0});
    check[0][0] = true;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if(arr[x][y] == -1){
            cout << "HaruHaru";
            return;
        }
        for(auto [dx, dy] : dir){
            int nx = x + dx * arr[x][y], ny = y + dy * arr[x][y];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || check[nx][ny]) continue;
            q.push({nx, ny});
            check[nx][ny] = true;
        }
    }
    cout << "Hing";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector(n, 0));
    check.assign(n, vector(n, 0));

    for(int i = 0;i < n;i++)
        for(int j =0;j < n;j++)
            cin >> arr[i][j];

    bfs();
    return 0;
}