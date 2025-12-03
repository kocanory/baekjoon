#include <iostream>
#include <vector>

using namespace std;

int k, n, f, a, b;
vector<vector<int>> friends;
vector<int> num, check;

bool selectable(int x) {
    for (auto c: check) {
        if (!friends[x][c]) return false;
    }
    return true;
}

void dfs(int now, int cnt) {
    if (cnt == k) {
        for (auto c : check)
            cout << c << "\n";
        exit(0);
    }

    for (int i = now + 1;i <= n;i++) {
        if (!friends[now][i] || !selectable(i)) continue;
        check.push_back(i);
        dfs(i, cnt + 1);
        check.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n >> f;
    friends.assign(n + 1, vector(n + 1, 0));
    num.assign(n + 1, 0);

    while (f--) {
        cin >> a >> b;
        friends[a][b] = 1;
        friends[b][a] = 1;

        num[a]++;
        num[b]++;
    }

    for (int i = 1;i <= n;i++) {
        if (num[i] < k - 1) continue;
        check.push_back(i);
        dfs(i, 1);
        check.pop_back();
    }
    cout << -1;
    return 0;
}