#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, k = 1;
vector<tuple<int, int, int>> arr;
vector<int> ans;
priority_queue<pair<int, int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ans.assign(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({b, a, c});
    }
    sort(arr.begin(), arr.end());

    for (auto [start, num, end] : arr) {
        if (pq.empty()) {
            pq.push({-end, k});
            ans[num] = k;
        }
        else {
            if (-pq.top().first <= start) {
                pq.push({-end, pq.top().second});
                ans[num] = pq.top().second;
                pq.pop();
            }
            else {
                ans[num] = ++k;
                pq.push({-end, k});
            }
        }
    }
    cout << k << "\n";
    for (int i = 1;i <= n;i++) cout << ans[i] << "\n";
    return 0;
}