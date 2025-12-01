#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, n, m, l, r, mid, ans;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> d >> n >> m;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;
    arr.push_back(d);
    sort(arr.begin(), arr.end());

    l = 1, r = d;

    while (l <= r) {
        mid = (l + r) / 2;
        int back = 0, deleted = 0;
        for (int &a : arr) {
            if (a - back < mid) deleted++;
            else back = a;
        }
        if (deleted > m) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}