#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, ans = 1;
vector<pair<int, int>> arr;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, {0, 0});

    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    pq.push(-arr[0].second);

    for (int i = 1; i < n; i++) {
        while (!pq.empty() && -pq.top() <= arr[i].first)
            pq.pop();
        pq.push(-arr[i].second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << "\n";
    return 0;
}