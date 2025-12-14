#include <iostream>
#include <vector>

using namespace std;

int n, m, l = 1, r = 1, ans;
vector<int> arr;

bool check(int mid) {
    int sum = 0;
    for (auto &a : arr)
        sum += min(a, mid);
    return sum <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for (int &a : arr) {
        cin >> a;
        r = max(r, a);
    }
    cin >> m;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}