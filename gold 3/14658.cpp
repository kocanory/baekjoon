#include <iostream>
#include <vector>

using namespace std;

int n, m, l, k, ans = 1e9;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> l >> k;

    for (int i = 0;i < k;i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    for (int i = 0;i < k;i++) {
        for (int j = 0;j < k;j++) {
            int x = arr[i].first, y = arr[j].second, cnt = k;
            for (int a = 0;a < k;a++) {
                auto [nx, ny] = arr[a];
                if (nx >= x && nx <= x + l && ny >= y && ny <= y + l)
                    cnt--;
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}