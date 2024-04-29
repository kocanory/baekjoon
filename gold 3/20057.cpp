#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int xdx[][10] = {{0, 0, -1, -1, -1, -1, -2, -2, -3, -2}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 2, 2, 3, 2}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}
};

int ydy[][10] = {{-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 2, 2, 3, 2}, 
    {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {0, 0, -1, -1, -1, -1, -2, -2, -3, -2}
};

int percent[] = {1, 1, 7, 7, 2, 2, 10, 10, 5};
int n, result = 0;
vector<vector<int>> arr;

void spread_sand(int x, int y, int dir){
    int nx = x + dx[dir], ny = y + dy[dir];
    if((nx < 0 || nx >= n || ny < 0 || ny >= n) || arr[nx][ny] == 0) return;
    
    int sand = arr[nx][ny], val = sand;
    for(int i = 0;i < 9;i++){
        int nxx = x + xdx[dir][i], nyy = y + ydy[dir][i];
        int per = percent[i];
        int plus = (val * per) / 100;
        
        if(nxx < 0 || nxx >= n || nyy < 0 || nyy >= n) result += plus;
        else arr[nxx][nyy] += plus;
        
        sand -= plus;
    }
    int nxx = x + xdx[dir][9], nyy = y + ydy[dir][9];
    if(nxx < 0 || nxx >= n || nyy < 0 || nyy >= n) result += sand;
    else arr[nxx][nyy] += sand;
    arr[nx][ny] = 0;
}

void check(){
    int x = n / 2, y = n / 2;
    int dir = 3, move = 1;
    
    while(true){
        
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < move;j++){
                spread_sand(x, y, dir);
                x += dx[dir];
                y += dy[dir];
            }
            dir = (dir + 3) % 4;
        }
        
        move++;
        if(move == n){
            for(int j = 0;j < move;j++){
                spread_sand(x, y, dir);
                x += dx[dir];
                y += dy[dir];
            }
            break;
        }
    }
    
    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    arr.assign(n, vector<int>(n, 0));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> arr[i][j];
    
    check();
    return 0;
}