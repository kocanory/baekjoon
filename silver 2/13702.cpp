#include <iostream>
#include <vector>

using namespace std;

long long n, k, l = 1, r = 0, mid, cnt, ans;
vector<long long> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);

    for (auto &a : arr) {
        cin >> a;
        r = max(r, a);
    }

    while (l <= r) {
        mid = (l + r) / 2, cnt = 0;
        for (auto &a : arr)
            cnt += a / mid;
        
        if (cnt >= k) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}