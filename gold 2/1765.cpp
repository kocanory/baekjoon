#include <iostream>
#include <vector>
#include <map>

using namespace std;

char c;
int n, m, a, b, ans = 0;
vector<int> p;
map<int, vector<int>> e;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)
        p[max(x, y)] = min(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    p.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) p[i] = i;

    while (m--) {
        cin >> c >> a >> b;
        if (c == 'F') join(a, b);
        else {
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }

    for (int i = 1;i <= n;i++) {
        if (e[i].size() > 1) {
            for (int j = 1;j < e[i].size();j++)
                join(e[i][j - 1], e[i][j]);
        }
    }

    for (int i = 1;i <= n;i++)
        if (p[i] == i)
            ans++;

    cout << ans;
    return 0;
}