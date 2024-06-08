#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, zero_area_num = 0;
vector<vector<int>> arr, area_num, answer;
vector<vector<bool>> visited;
vector<int> zero_area_size;

void bfs(int a, int b){
    queue<tuple<int, int>> q;
    q.push({a, b});
    area_num[a][b] = zero_area_num;
    visited[a][b] = true;

    int count = 1;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == 0 && !visited[nx][ny]){
                visited[nx][ny] = true;
                area_num[nx][ny] = zero_area_num;
                q.push({nx, ny});
                count++;
            }
        }
    }
    zero_area_size.push_back(count);
}

void solve(){
    for(int i =0 ;i < n;i++)
        for(int j = 0;j < m;j++)
            if(arr[i][j] == 0 && !visited[i][j]){
                bfs(i, j);
                zero_area_num++;
            }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == 1){
                set<int> search;
                for(int d = 0;d < 4;d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(arr[nx][ny] == 0){
                        if(search.find(area_num[nx][ny]) == search.end()){
                            search.insert(area_num[nx][ny]);
                            answer[i][j] += zero_area_size[area_num[nx][ny]];
                        }
                    }
                }
                answer[i][j]++;
                answer[i][j] %= 10;
            }
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << answer[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector<int>(m));
    area_num.assign(n, vector<int>(m, -1));
    answer.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m));

    for(int i = 0;i < n;i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            arr[i][j] = str[j] - '0';
    }

    solve();
    return 0;
}