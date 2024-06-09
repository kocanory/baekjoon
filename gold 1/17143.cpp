#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int R, C, M, answer = 0;
vector<tuple<int, int, int>> Sharks[102][102];
vector<vector<int>> dir = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int change_dir(int d){
    if(d == 1) return 2;
    if(d == 2) return 1;
    if(d == 3) return 4;
    if(d == 4) return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> M;
    for(int i = 0;i < M;i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        if(d == 1 || d == 2) s %= ((R - 1) * 2);
        if(d == 3 || d == 4) s %= ((C - 1) * 2);
        Sharks[r][c].emplace_back(s, d, z);
    }

    int idx = 0;
    while(++idx <= C){
        for(int i = 1;i <= R;i++){
            if(!Sharks[i][idx].empty()){
                answer += get<2>(Sharks[i][idx][0]);
                Sharks[i][idx].pop_back();
                break;
            }
        }

        vector<tuple<int, int, int>> newSharks[102][102];
        for(int i = 1;i <= R;i++){
            for(int j = 1;j <= C;j++){
                if(Sharks[i][j].empty()) continue;
                auto[cs, cd, cz] = Sharks[i][j][0];
                int cr = i, cc = j, s = cs;
                Sharks[i][j].pop_back();

                while(s--){
                    int nr = cr + dir[cd][0], nc = cc + dir[cd][1];
                    if(nr < 1 || nr > R || nc < 1 || nc > C) cd = change_dir(cd);
                    cr += dir[cd][0];
                    cc += dir[cd][1];
                }
                if(newSharks[cr][cc].empty()) newSharks[cr][cc].emplace_back(cs, cd, cz);
                else{
                    if(get<2>(newSharks[cr][cc][0]) < cz){
                        newSharks[cr][cc].pop_back();
                        newSharks[cr][cc].emplace_back(cs, cd, cz);
                    }
                }
            }
        }
        for(int i = 1;i <= R;i++)
            for(int j = 1;j <= C;j++)
                Sharks[i][j] = newSharks[i][j];
    }
    cout << answer << "\n";
    return 0;
}