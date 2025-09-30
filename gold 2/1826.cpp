#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, dist, fuel, ans = 0, idx = 0;
vector<pair<int, int>> arr;
priority_queue<int> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, {0, 0});

    for (auto &[a, b] : arr) cin >> a >> b;
    sort(arr.begin(), arr.end(), cmp);

    cin >> dist >> fuel;

    for (int i = 1;i < dist;i++) {
        fuel--;
        if (idx < n && arr[idx].first == i) {
            pq.push(arr[idx++].second);
        }

        if (!fuel) {
            if (!pq.empty()) {
                fuel = pq.top(); pq.pop();
                ans++;
            }
            else {
                ans = -1;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}