#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, ans = 0;
unordered_map<int, vector<int>> graph;
vector<vector<int>> dist(52, vector(52, 0)), flow(52, vector(52, 0));

int conv(char c) {
    if (isupper(c))
        return c - 'A' + 26;
    return c - 'a';
}

void maxflow(int s, int e) {
    while (true) {
        vector back(52, -1);
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (auto next : graph[now]) {
                if (dist[now][next] - flow[now][next] > 0 && back[next] == -1) {
                    back[next] = now;
                    q.push(next);
                    if (next == e) break;
                }
            }
            if (back[e] != -1) break;
        }
        if (back[e] == -1) break;

        int temp = 1e9;
        for (int i = e;i != s;i = back[i]) 
            temp = min(temp, dist[back[i]][i] - flow[back[i]][i]);

        for (int i = e;i != s;i = back[i]) {
            flow[back[i]][i] += temp;
            flow[i][back[i]] -= temp;
        }
        ans += temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        graph[conv(a)].push_back(conv(b));
        graph[conv(b)].push_back(conv(a));
        dist[conv(a)][conv(b)] += c;
        dist[conv(b)][conv(a)] += c;
    }
    maxflow(conv('A'), conv('Z'));
    cout << ans;
    return 0;
}