#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, l = 1, r, ans = 1e9;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(m, 0);

    for (int i = 0;i < m;i++) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }

    while (l <= r) {
        int mid = (l + r) / 2, cnt = 0;
        for (auto a : arr) cnt += ceil(a / double(mid));
        if (cnt <= n) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}