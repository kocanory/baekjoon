#include <iostream>

using namespace std;

int dx[] = {0, 1, 1, -1};
int dy[] = {1, 0, 1, 1};

int arr[20][20];
bool visited[20][20][4];
bool flag = true;
int win, wx, wy;

void check(int x, int y){
    for(int d = 0;d < 4;d++){
        if(visited[x][y][d]) continue;
        visited[x][y][d] = true;
        int nx = x, ny = y, cnt = 1;
        while(true){
            nx += dx[d], ny += dy[d];
            if(nx < 1 || nx > 19 || ny < 1 || ny > 19 || arr[nx][ny] != arr[x][y]){
                if(cnt == 5){
                    win = arr[x][y];
                    wx = x, wy = y;
                    flag = false;
                    return;
                }
                break;
            }
            visited[nx][ny][d] = true;
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 1;i <= 19;i++)
        for(int j = 1;j <= 19;j++)
            cin >> arr[i][j];
            
    for(int j = 1;j <= 19 && flag;j++)
        for(int i = 1;i <= 19 && flag;i++)
            if(arr[i][j])
                check(i, j);            

    if(win) cout << win << "\n" << wx << " " << wy << "\n";
    else cout << 0 << "\n";
    return 0;
}