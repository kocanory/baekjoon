#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
long long ans = 0;
bool flag = false;
vector<pair<int, int>> arr;
vector<tuple<int, int, int>> check;
priority_queue<tuple<int, int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, {0, 0});
    for (auto &[a, b] : arr) cin >> a >> b;

    for (int i = 0;i < k;i++) {
        if (i == n) {
            flag = true;
            break;
        }
        pq.push({-arr[i].second, -(i + 1), arr[i].first});
    }

    if (flag) {
        while (!pq.empty()) {
            auto [t, num, id] = pq.top();
            pq.pop();
            check.push_back({-t, num, id});
        }
    }
    else {
        for (int i = k;i < n;i++) {
            auto [t, num, id] = pq.top();
            pq.pop();
            check.push_back({-t, num, id});
            pq.push({-arr[i].second + t, num, arr[i].first});
        }
        while (!pq.empty()) {
            auto [t, num, id] = pq.top();
            pq.pop();
            check.push_back({-t, num, id});
        }
    }
    sort(check.begin(), check.end());
    for (long long i = 0;i < n;i++) {
        auto [t, num, id] = check[i];
        ans += (i + 1) * id;
    }
    cout << ans;
    return 0;
}