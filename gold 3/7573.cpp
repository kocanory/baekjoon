#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, m, ans = 0;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> m;
    arr.assign(m, {0, 0});
    for (auto &[x, y] : arr) cin >> x >> y;
    sort(arr.begin(), arr.end());

    for (int w = 1; w < l / 2; w++) {
        int h = l / 2 - w;

        for (int i = 0;i < m;i++) {
            auto [x, y] = arr[i];
            for (int k = 0;k <= w;k++) {
                int cnt = 1;
                for (int j = i + 1;j < m;j++) {
                    auto [nx, ny] = arr[j];
                    if (nx > x + h) break;
                    if (ny >= y - k && ny <= y - k + w) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
    return 0;
}