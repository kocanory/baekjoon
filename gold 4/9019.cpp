#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int t, a, b;
vector<bool> visited;

void bfs() {
    queue<tuple<int, string>> q;
    q.push({a, ""});
    visited.assign(10001, false);
    visited[a] = true;

    while(!q.empty()) {
        auto[now, cmd] = q.front(); q.pop();
        if(now == b) {
            cout << cmd << "\n";
            return;
        }
        int d = (now * 2) % 10000;
        if(!visited[d]) {
            visited[d] = true;
            q.push({d, cmd + 'D'});
        }

        int s = (now + 9999) % 10000;
        if(!visited[s]) {
            visited[s] = true;
            q.push({s, cmd + 'S'});
        }

        int l = (now % 1000) * 10 + now / 1000;
        if(!visited[l]) {
            visited[l] = true;
            q.push({l, cmd + 'L'});
        }

        int r = (now % 10) * 1000 + now / 10;
        if(!visited[r]) {
            visited[r] = true;
            q.push({r, cmd + 'R'});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> a >> b;
        bfs();
    }
    return 0;
}