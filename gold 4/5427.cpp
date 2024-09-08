#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int t, n, m;
vector<string> arr;
queue<tuple<int, int>> fq, sq;

void moveFire(){
    int size = fq.size();
    for(int i = 0;i < size;i++){
        auto[x, y] = fq.front(); fq.pop();
        for(int d = 0;d < 4;d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != '.') continue;
            arr[nx][ny] = '*';
            fq.push({nx, ny});
        }
    }
}

int move(){
    int time = 0;
    while(!sq.empty()){
        int size = sq.size();
        time++;
        moveFire();
        for(int i = 0;i < size;i++){
            auto[x, y] = sq.front(); sq.pop();
            for(int d = 0;d < 4;d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) return time;
                if(arr[nx][ny] != '.') continue;
                arr[nx][ny] = '@';
                sq.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> m >> n;
        arr.assign(n, "");
        while(!sq.empty()) sq.pop();
        while(!fq.empty()) fq.pop();
        
        for(int i = 0;i < n;i++){
            cin >> arr[i];
            for(int j = 0;j < m;j++){
                if(arr[i][j] == '@') sq.push({i, j});
                if(arr[i][j] == '*') fq.push({i, j});
            }
        }
        int time = move();
        if(time == -1) cout << "IMPOSSIBLE" << "\n";
        else cout << time << "\n";
    }
    return 0;
}