#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>>

using namespace std;

int n, m;
unordered_map<int, vector<pair<int, int>>> graph;
vector<int> inDeg, cnt, ans;
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    inDeg.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    for(int i = 0;i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        inDeg[b]++;
    }

    q.push(n);
    cnt[n] = 1;

    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(graph[now].empty()) ans.push_back(now);
        for(auto &[next, n_cost] : graph[now]) {
            cnt[next] += cnt[now] * n_cost;
            if(--inDeg[next] == 0) q.push(next);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto &a : ans) cout << a << " " << cnt[a] << "\n";
    return 0;
}