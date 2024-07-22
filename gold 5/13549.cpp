#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
vector<bool> visited(100010, false);

void bfs(){
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    pq.push({0, n});
    visited[n] = 0;
    
    while(!pq.empty()){
        auto[count, now] = pq.top(); pq.pop();
        if(now == k){
            cout << count << "\n";
            return;
        }
        if(now * 2 <= 100000 && !visited[now * 2]){
            visited[now * 2] = true;
            pq.push({count, now * 2});
        }
        
        if(now + 1 <= 100000 && !visited[now + 1]){
            visited[now + 1] = true;
            pq.push({count + 1, now + 1});
        }
        
        if(now - 1 >= 0 && !visited[now - 1]){
            visited[now - 1] = true;
            pq.push({count + 1, now - 1});
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