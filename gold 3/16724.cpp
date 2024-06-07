#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, answer = 0;
vector<vector<int>> arr;
vector<vector<int>> visited;

bool check(int i, int j){
    if(visited[i][j] == 0) return true;
    else if(visited[i][j] == 1) return false;

    visited[i][j] = 0;
    bool res = check(i + dx[arr[i][j]], j + dy[arr[i][j]]);
    visited[i][j] = 1;

    return res;
}

void solve(){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(check(i, j)){
                answer++;
            }
        }
    }

    cout << answer << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    visited.assign(n, vector<int>(m, -1));

    for(int i = 0;i < n;i++){
        string str;
        cin >> str;
        for(int j = 0;j < m;j++){
            switch(str[j]){
                case 'U':
                    arr[i][j] = 0;
                    break;
                case 'R':
                    arr[i][j] = 1;
                    break;
                case 'D':
                    arr[i][j] = 2;
                    break;
                case 'L':
                    arr[i][j] = 3;
                    break;
            }
        }
    }
    solve();
    return 0;
}