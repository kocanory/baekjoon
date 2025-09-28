#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m, a, b, cnt;
vector<bool> check;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        arr.clear();
        cin >> n >> m;
        for (int i = 0;i < m;i++) {
            cin >> a >> b;
            arr.push_back({b, a});
        }

        check.assign(n + 1, false);
        cnt = 0;
        sort(arr.begin(), arr.end());

        for (auto [b, a] : arr) {
            for (int i = a; i <= b; i++) {
                if (!check[i]) {
                    check[i] = true;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}