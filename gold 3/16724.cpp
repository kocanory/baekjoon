#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, answer = 0;
vector<vector<int>> arr, visited;

bool check(int x, int y){
    if(visited[x][y] == 0) return true;
    else if(visited[x][y] == 1) return false;
    
    visited[x][y] = 0;
    bool res = check(x + dx[arr[x][y]], y + dy[arr[x][y]]);
    visited[x][y] = 1;
    
    return res;
}

void solve(){
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(check(i, j))
                answer++;
                
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    visited.assign(n, vector<int>(m, -1));
    
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < m;j++){
            switch(s[j]){
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