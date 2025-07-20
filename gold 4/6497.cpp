#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)
        parent[max(x, y)] = min(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<tuple<int, int, int>> arr;
        parent.assign(m, 0);
        for (int i = 0;i < m;i++) parent[i] = i;

        for (int i = 0;i < n;i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr.push_back({z, x, y});
        }
        sort(arr.begin(), arr.end());

        int ans = 0;
        for (auto [z, x, y] : arr) {
            x = find(x), y = find(y);
            if (x != y) join(x, y);
            else ans += z;
        }
        cout << ans << '\n';
    }
    return 0;
}