#include <iostream>
#include <queue>

using namespace std;

int a, b;
queue<pair<int, long long>> q;

int bfs() {
    q.push({1, a});
    while (!q.empty()) {
        auto [cnt, now] = q.front(); q.pop();
        if (now == b) return cnt;
        if (2 * now <= b)
            q.push({cnt + 1, 2 * now});
        if (10 * now + 1 <= b)
            q.push({cnt + 1, 10 * now + 1});
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << bfs() << "\n";
    return 0;
}