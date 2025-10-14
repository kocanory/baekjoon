#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m, ans = 1e9, Min = 1e9;
vector<vector<int>> arr;
priority_queue<tuple<int, int, int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, vector(m, 0));

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
        sort(arr[i].begin(), arr[i].end(), greater<int>());
        Min = min(Min, arr[i][0]);
        pq.push({arr[i][0], i, 0});
    }

    while (!pq.empty()) {
        auto [now, idx, arrIdx] = pq.top(); pq.pop();
        ans = min(ans, now - Min);
        if (arrIdx == m - 1) break;
        Min = min(Min, arr[idx][++arrIdx]);
        pq.push({arr[idx][arrIdx], idx, arrIdx});
    }
    cout << ans;
    return 0;
}