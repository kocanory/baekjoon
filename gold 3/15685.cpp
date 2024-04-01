#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n, x, y, d, g, ex, ey, result;
vector<vector<bool>> map(110, vector<bool>(110, false));
vector<int> dragon;

void rotate(){
    int dir;
    for(int i = dragon.size() - 1;i >= 0;i--){
        dir = (dragon[i] + 1) % 4;
        ex += dx[dir], ey += dy[dir];
        map[ex][ey] = true;
        dragon.push_back(dir);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    while(n--){
        dragon.clear();
        cin >> y >> x >> d >> g;
        dragon.push_back(d);
        ex = x + dx[d], ey = y + dy[d];
        map[x][y] = true;
        map[ex][ey] = true;
        while(g--) rotate();
    }
    
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            if(map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
                result++;
        }
    }
    
    cout << result << "\n";
    return 0;
}