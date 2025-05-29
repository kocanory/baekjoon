#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int l, r, c;
vector<tuple<int, int, int>> dir = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        
        vector arr(l, vector<string>(r));
        vector check(l, vector(r, vector(c, false)));
        queue<tuple<int, int, int, int>> q;
        bool flag = false;
        
        for(int k = 0;k < l;k++)
            for(int i = 0;i < r;i++){
                cin >> arr[k][i];
                for(int j = 0;j < c;j++)
                    if(arr[k][i][j] == 'S')
                        q.push({k, i, j, 0});
            }
        
        while(!q.empty()){
            auto [z, x, y, cnt] = q.front(); q.pop();
            if(arr[z][x][y] == 'E'){
                cout << "Escaped in " << cnt << " minute(s).\n";
                flag = true;
                break;
            }
            
            for(auto [dz, dx, dy] : dir){
                int nz = z + dz, nx = x + dx, ny = y + dy;
                if(nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c || check[nz][nx][ny] || arr[nz][nx][ny] == '#')
                    continue;
                check[nz][nx][ny] = true;
                q.push({nz, nx, ny, cnt + 1});
            }
        }
        
        if(!flag)
            cout << "Trapped!" << "\n";
    }

    return 0;
}