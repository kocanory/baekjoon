#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n;
pair<int, int> home, festival;
vector<pair<int, int>> convenience;
vector<bool> visited;

bool bfs() {
    queue<pair<int, int>> q;
    q.push(home);
    while(!q.empty()) {
        pair<int, int> now = q.front(); q.pop();
        if(abs(now.first - festival.first) + abs(now.second - festival.second) <= 1000) return true;
        for(int i = 0;i < n;i++) {
            if(visited[i]) continue;
            if(abs(now.first - convenience[i].first) + abs(now.second - convenience[i].second) <= 1000) {
                visited[i] = true;
                q.push(convenience[i]);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        visited.assign(n, false);
        convenience.assign(n, pair<int, int>());

        cin >> home.first >> home.second;
        for(int i = 0;i < n;i++) cin >> convenience[i].first >> convenience[i].second;
        cin >> festival.first >> festival.second;
        bool flag = bfs();
        cout << (flag ? "happy" : "sad") << "\n";
    }

    return 0;
}