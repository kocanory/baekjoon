#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, q;
vector<vector<int>> arr;
vector<int> check;
priority_queue<pair<int, int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    arr.assign(n, {0, 0, 0});
    check.assign(n + 1, 0);
    for (int i = 0;i < n;i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        arr[i] = {x1, x2, i + 1};
    }

    sort(arr.begin(), arr.end());
    pq.push({-arr[0][1], 0});
    check[arr[0][2]] = 0;

    for (int i = 1;i < n;i++) {
        auto[e, r] = pq.top();
        e = -e;
        if (arr[i][0] <= e) {
            if (arr[i][1] > e) {
                pq.pop();
                pq.push({-arr[i][1], r});
            }
            check[arr[i][2]] = r;
        }
        else {
            pq.pop();
            pq.push({-arr[i][1], r + 1});
            check[arr[i][2]] = r + 1;
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (check[u] == check[v] ? 1 : 0) << "\n";
    }
    return 0;
}