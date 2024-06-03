#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> vec(10, vector<int>(10)), tvec(10, vector<int>(10));
int answer = 1e9, count = 0;

void turn(int x, int y){
    tvec[x][y] = !tvec[x][y];
    for(int i = 0;i < 4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
        tvec[nx][ny] = !tvec[nx][ny];
    }
}

bool is_solved(){
    for(int i = 1;i < 10;i++){
        for(int j = 0;j < 10;j++){
            if(tvec[i - 1][j]){
                turn(i, j);
                count++;
            }
        }
    }
    for(int j = 0;j < 10;j++)
        if(tvec[9][j]) return false;
    return true;
}

void solve(){
    for(int k = 0;k < 1024;k++) {
        tvec = vec;

        count = 0;
        for (int i = 0; i < 10; i++) {
            if (k & (1 << i)){
                count++;
                turn(0, i);
            }
        }

        if(is_solved()) answer = min(answer, count);
    }
    if(answer == 1e9) cout << -1 << "\n";
    else cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0;i < 10;i++) {
        string str;
        cin >> str;
        for(int j = 0;j < 10;j++){
            if(str[j] == 'O') vec[i][j] = 1;
            else vec[i][j] = 0;
        }
    }

    solve();
    return 0;
}