#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll l, w, h, n, vol, ans = 0, back = 0;
vector<pair<ll, ll>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> w >> h >> n;
    arr.assign(n, {0, 0});
    vol = l * w * h;

    for (auto &[a, b] : arr) cin >> a >> b;
    sort(arr.begin(), arr.end(), greater<pair<ll, ll>>());

    for (auto [s, c] : arr) {
        back <<= 3;
        ll v = 1 << s;

        long long maxCnt = (l / v) * (w / v) * (h / v) - back;
        maxCnt = min(c, maxCnt);
        ans += maxCnt;
        back += maxCnt;
    }

    cout << (vol == back ? ans : -1);
    return 0;
}