#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, int> warp;
vector<int> visited(101);

void bfs() {
    queue<tuple<int, int>> q;
    q.emplace(1, 0);
    while(!q.empty()) {
        auto[now, count] = q.front(); q.pop();
        if(now == 100) {
            cout << count << "\n";
            return;
        }
        for(int i = 1;i <= 6;i++) {
            int next = now + i;
            if(next <= 100) {
                while(warp[next]) next = warp[next];
                if(!visited[next]) {
                    visited[next] = true;
                    q.emplace(next, count + 1);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i < n + m;i++) {
        int a, b;
        cin >> a >> b;
        warp[a] = b;
    }
    bfs();
    return 0;
}