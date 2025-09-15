#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, total = 0, sum = 0, cnt = 0;
vector<tuple<int, int, int>> arr;
vector<int> parent(53);

int conv(char c) {
    if (isupper(c))
        return c - 'A' + 27;
    return c - 'a' + 1;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) parent[max(x, y)] = min(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1;i <= 52;i++) parent[i] = i;

    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for (int j = 0;j < n;j++) {
            if (s[j] == '0') continue;
            total += conv(s[j]);
            if (i == j) continue;
            arr.push_back({conv(s[j]), i, j});
        }
    }
    sort(arr.begin(), arr.end());

    for (auto [d, i, j] : arr) {
        if (find(i) != find(j)) {
            join(i, j);
            sum += d;
            cnt++;
        }
    }
    if (cnt < n - 1) cout << -1;
    else cout << total - sum;
    return 0;
}