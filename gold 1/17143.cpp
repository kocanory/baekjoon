#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int R, C, M, answer = 0;
vector<vector<int>> dir = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<tuple<int, int, int, int, int>> Sharks[102][102];

bool in_range(int r, int c){
    return r > 0 && r <= R && c > 0 && c <= C;
}

int change_dir(int d){
    if(d == 1) return 2;
    if(d == 2) return 1;
    if(d == 3) return 4;
    if(d == 4) return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> M;
    for(int i = 0;i < M;i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        if(d == 1 || d == 2) s %= ((R - 1) * 2);
        if(d == 3 || d == 4) s %= ((C - 1) * 2);
        Sharks[r][c].push_back({r, c, s, d, z});
    }
    
    int K = 0;
    while(++K <= C){
        for(int i = 1;i <= R;i++){
            if(!Sharks[i][K].empty()){
                answer += get<4>(Sharks[i][K][0]);
                Sharks[i][K].pop_back();
                break;
            }
        }
        vector<tuple<int, int, int, int, int>> newSharks[102][102];
        for(int i = 1;i <= R;i++){
            for(int j = 1;j <= C;j++){
                if(Sharks[i][j].empty()) continue;
                auto &[cr, cc, cs, cd, cz] = Sharks[i][j][0];
                Sharks[i][j].pop_back();

                int s = cs;
                while(s--){
                    int nr = cr + dir[cd][0], nc = cc + dir[cd][1];
                    if(!in_range(nr, nc)) cd = change_dir(cd);

                    cr += dir[cd][0];
                    cc += dir[cd][1];
                }

                if(!newSharks[cr][cc].empty()){
                    if(get<4>(newSharks[cr][cc][0]) < cz){
                        newSharks[cr][cc].pop_back();
                        newSharks[cr][cc].push_back({cr, cc, cs, cd, cz});
                    }
                }
                else newSharks[cr][cc].push_back({cr, cc, cs, cd, cz});
            }
        }

        for(int i = 1;i <= R;i++)
            for(int j = 1;j <= C;j++)
                Sharks[i][j] = newSharks[i][j];
    }
    cout << answer << "\n";
    return 0;
}