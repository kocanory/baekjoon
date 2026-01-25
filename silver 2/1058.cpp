#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, ans = 0;
vector<string> arr;

int bfs(int s) {
    vector<bool> check(n);
    queue<pair<int, int>> q;
    q.push({s, 0});
    check[s] = true;
    int cnt = 0;

    while (!q.empty()) {
        auto [now, depth] = q.front(); q.pop();
        if (depth >= 2) continue;
        for (int i = 0;i <n;i++) {
            if (!check[i] && arr[now][i] == 'Y') {
                check[i] = true;
                q.push({i, depth + 1});
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, "");

    for (int i = 0;i < n;i++) cin >> arr[i];
    for (int i = 0;i < n;i++) ans = max(ans, bfs(i));
    cout << ans;
}