#include <iostream>
#include <vector>

using namespace std;

int m, n, l = 1, r = 0, mid, cnt, ans;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    arr.assign(n, 0);

    for (int &a : arr) {
        cin >> a;
        r = max(r, a);
    }

    while (l <= r) {
        mid = (l + r) / 2, cnt = 0;
        for (int &a : arr) cnt += a / mid;
        if (cnt < m)
            r =  mid - 1;
        else {
            l = mid + 1;
            ans = mid;
        }
    }

    cout << ans;
    return 0;
}