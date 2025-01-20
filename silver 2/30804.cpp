#include <iostream>
#include <queue>

using namespace std;

int n, s, t = 0, ans = 0;
vector<int> cnt(10);
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> s;
        if (!cnt[s]) t++;
        cnt[s]++;
        q.push(s);
        while (t > 2) {
            s = q.front(); q.pop();
            cnt[s]--;
            if (!cnt[s]) t--;
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans << "\n";
}