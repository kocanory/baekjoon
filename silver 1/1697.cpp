#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n, k;
vector<bool> visited(100010, false);

void bfs(){
    queue<tuple<int, int>> q;
    visited[n] = true;
    q.push({n, 0});
    
    while(!q.empty()){
        auto[now, count] = q.front(); q.pop();
        if(now == k){
            cout << count << "\n";
            return;
        }
        
        if(now + 1 >= 0 && now + 1 < 100001){
            if(!visited[now + 1]){
                visited[now + 1] = true;
                q.push({now + 1, count + 1});
            }
        }
        
        if(now - 1 >= 0 && now - 1 < 100001){
            if(!visited[now - 1]){
                visited[now - 1] = true;
                q.push({now - 1, count + 1});
            }
        }
        
        if(2 * now >= 0 && 2 * now < 100001){
            if(!visited[2 * now]){
                visited[2 * now] = true;
                q.push({2 * now, count + 1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    bfs();
    return 0;
}