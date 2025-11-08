#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n, m;
char u, v;
string be;
map<char, vector<char>> graph;

bool bfs(char s, char e) {
    queue<char> q;
    q.push(s);
    map<char, bool> visited;
    visited[s] = true;

    while (!q.empty()) {
        auto now = q.front(); q.pop();
        if (now == e) return true;
        for (auto next : graph[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> u >> be >> v;
        graph[u].push_back(v);
    }
    
    cin >> m;
    while (m--) {
        cin >> u >> be >> v;
        cout << (bfs(u, v) ? "T" : "F") << endl;
    }
    return 0;
}