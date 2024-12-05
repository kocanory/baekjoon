#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m, r;
vector<vector<int>> arr;

void rotate(int cnt){
    for(int i = 0;i < cnt;i++){
        int x = i, y = i, dir = 0, start = arr[i][i];
        while(dir < 4){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx == i && ny == i) break;
            if(i <= nx && nx < n - i && i <= ny && ny < m - i){
                arr[x][y] = arr[nx][ny];
                x = nx, y = ny;
            }
            else dir++;
        }
        arr[i + 1][i] = start;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> r;
    arr.assign(n, vector<int>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];
            
    int cnt = min(n, m) / 2;
    for(int i = 0;i < r;i++)
        rotate(cnt);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}