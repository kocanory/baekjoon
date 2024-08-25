#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, t, ex, ey;
queue<tuple<int, int>> b, w;
vector<string> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 'D'){
                ex = i;
                ey = j;
            }
            if(arr[i][j] == '*') w.push({i, j});
            if(arr[i][j] == 'S') b.push({i, j});
        }
    }

    while(!b.empty()){
        int w_len = w.size();
        for(int i = 0;i < w_len;i++){
            auto[wx, wy] = w.front(); w.pop();
            for(int d = 0;d < 4;d++){
                int nwx = wx + dx[d], nwy = wy + dy[d];
                if(nwx < 0 || nwx >= n || nwy < 0 || nwy >= m) continue;
                if(arr[nwx][nwy] == '.'){
                    w.push({nwx, nwy});
                    arr[nwx][nwy] = '*';
                }
            }
        }

        int b_len = b.size();
        for(int i = 0;i < b_len;i++){
            auto[bx, by] = b.front(); b.pop();
            for(int d = 0;d < 4;d++){
                int nbx = bx + dx[d], nby = by + dy[d];
                if(nbx < 0 || nbx >= n || nby < 0 || nby >= m) continue;
                if(nbx == ex && nby == ey){
                    cout << t + 1 << "\n";
                    return 0;
                }
                if(arr[nbx][nby] == '.'){
                    b.push({nbx, nby});
                    arr[nbx][nby] = 'S';
                }
            }
        }
        t++;
    }
    cout << "KAKTUS" << "\n";
    return 0;
}