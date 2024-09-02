#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
vector<int> parent(200010), path;
vector<bool> visited(200010);
queue<tuple<int, int>> q;

void bfs(){
    q.push({0, n});
    visited[n] = true;
    
    while(!q.empty()){
        auto[count, now] = q.front(); q.pop();
        if(now == k){
            cout << count << "\n";
            while(now != n){
                path.push_back(now);
                now = parent[now];
            }
            path.push_back(n);
            for(int i = path.size() - 1;i >= 0;i--)
                cout << path[i] << " ";
        }
        if(now + 1 <= 200000 && !visited[now + 1]){
            visited[now + 1] = true;
            q.push({count + 1, now + 1});
            parent[now + 1] = now;
        }
        if(now - 1 >= 0 && !visited[now - 1]){
            visited[now - 1] = true;
            q.push({count + 1, now - 1});
            parent[now - 1] = now;
        }
        if(now * 2 <= 200000 && !visited[now * 2]){
            visited[now * 2] = true;
            q.push({count + 1, now * 2});
            parent[now * 2] = now;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    bfs();
    return 0;
}