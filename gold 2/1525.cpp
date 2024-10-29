#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string s, e = "123456780";
unordered_map<string, bool> visited;

int bfs(){
    queue<pair<string, int>> q;
    q.push({s, 0});
    visited[s] = true;
    
    while(!q.empty()){
        auto[now, count] = q.front(); q.pop();
        if(now == e) return count;
        int zero = now.find('0');
        int x = zero / 3, y = zero % 3;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            string next = now;
            swap(next[x * 3 + y], next[nx * 3 + ny]);
            if(!visited[next]){
                visited[next] = true;
                q.push({next, count + 1});
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
    
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++){
            int a;
            cin >> a;
            s += (a + '0');
        }
        
    cout << bfs() << "\n";

    return 0;
}