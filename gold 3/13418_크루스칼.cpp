#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q, Min = 0, Max = 0;
vector<int> parent;
vector<tuple<int, int, int>> arr;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)
        parent[max(x, y)] = min(x, y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    parent.assign(n + 1, 0);
    for (int i = 0;i <= n;i++) parent[i] = i;

    for (int i = 0;i <= q;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({c, a, b});
    }

    sort(arr.begin(), arr.end());
    for (auto[c, a, b] : arr) {
        if (find(a) != find(b)) {
            join(a, b);
            if (!c) Max++;
        }
    }

    for (int i = 0;i <= n;i++) parent[i] = i;
    sort(arr.begin(), arr.end(), greater<>());
    for (auto[c, a, b] : arr) {
        if (find(a) != find(b)) {
            join(a, b);
            if (!c) Min++;
        }
    }

    cout << Max * Max - Min * Min;
    return 0;
}