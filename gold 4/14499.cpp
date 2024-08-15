#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int n, m, x, y, k;
vector<vector<int>> map;
vector<int> order, dice(7);

void roll(int dir){
    switch(dir){
        case 1:
            dice = {0, dice[3], dice[1], dice[6], dice[4], dice[5], dice[2]};
            break;
        case 2:
            dice = {0, dice[2], dice[6], dice[1], dice[4], dice[5], dice[3]};
            break;
        case 3:
            dice = {0, dice[4], dice[2], dice[3], dice[6], dice[1], dice[5]};
            break;
        case 4:
            dice = {0, dice[5], dice[2], dice[3], dice[1], dice[6], dice[4]};
            break;
        default:
            return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> x >> y >> k;
    map.assign(n, vector<int>(m));
    order.assign(k, 0);
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> map[i][j];
    for(int i = 0;i < k;i++)
        cin >> order[i];
        
    for(auto &o : order){
        int nx = x + dx[o], ny = y + dy[o];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        x = nx, y = ny;
        roll(o);
        cout << dice[1] << "\n";
        if(map[nx][ny] == 0){
            map[nx][ny] = dice[6];
        }
        else{
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
    }
    return 0;
}