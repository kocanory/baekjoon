#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int t, k, m, p;
unordered_map<int, vector<int>> graph, num;
vector<int> indeg, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> k >> m >> p;
        indeg.assign(m + 1, 0);
        ans.assign(m + 1, 0);
        graph.clear();
        num.clear();
        queue<int> q;

        for (int i = 0;i < p;i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            indeg[b]++;
        }

        for (int i = 1;i <= m;i++)
            if (indeg[i] == 0) {
                q.push(i);
                ans[i] = 1;
            }

        while (!q.empty()) {
            int now = q.front(); q.pop();

            for (auto next : graph[now]) {
                indeg[next]--;
                num[next].push_back(ans[now]);

                if (indeg[next] == 0) {
                    q.push(next);

                    int mnum = *max_element(num[next].begin(), num[next].end());
                    int cnt = 0;
                    for (auto a : num[next])
                        if (a == mnum)
                            cnt++;
                    if (cnt == 1) ans[next] = mnum;
                    else ans[next] = mnum + 1;
                }
            }
        }
        cout << k << " " << *max_element(ans.begin(), ans.end()) << "\n";
    }

    return 0;
}