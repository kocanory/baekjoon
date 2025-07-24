#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N, M, K, ans = 0;
vector<tuple<int, int, int, int, int>> fireball;
vector<vector<vector<tuple<int, int, int, int, int>>>> arr;
vector<pair<int, int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<int> t_dir = {0, 2, 4, 6}, f_dir = {1, 3, 5, 7};

void move(){
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++)
            arr[i][j].clear();
            
    for(auto &[r, c, m, s, d] : fireball){
        int v = s % N;
        int nx = (r + dir[d].first * v - 1 + N) % N + 1, ny = (c + dir[d].second * v - 1 + N) % N + 1;
        arr[nx][ny].push_back({nx, ny, m, s, d});
        r = nx, c = ny;
    }
}

void sum(){
    vector<tuple<int, int, int, int, int>> temp;
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++){
            if(arr[i][j].empty()) continue;
            if(arr[i][j].size() == 1){
                temp.push_back(arr[i][j][0]);
                continue;
            }
            int mSum = 0, sSum = 0, cnt = arr[i][j].size();
            bool even = true, odd = true;
            
            for(auto [r, c, m, s, d] : arr[i][j]){
                mSum += m;
                sSum += s;
                if(d % 2) even = false;
                else odd = false;
            }
            
            int m = mSum / 5, s = sSum / cnt;
            if(m == 0) continue;
            if(even || odd){
                for(auto d : t_dir)
                    temp.push_back({i, j, m, s, d});
            }   
            else{
                for(auto d : f_dir)
                    temp.push_back({i, j, m, s, d});
            }
        }
    fireball = temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    arr.assign(N + 1, vector<vector<tuple<int, int, int, int, int>>>(N + 1));
    
    while(M--){
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireball.push_back({r, c, m, s, d});
        arr[r][c].push_back({r, c, m, s, d});
    }

    while(K--){
        move();
        sum();
    }
    
    for(auto [r, c, m, s, d] : fireball)
        ans += m;
    cout << ans;
    return 0;
}