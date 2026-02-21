#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n, sum, half, l = 0, r = 0, mid, cnt, ans;
vector<vector<long long>> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector<long long>(n));

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
            r = max(r, arr[i][j]);
        }
    }
    half = ceil(sum / (double)2);

    while (l <= r) {
        mid = (l + r) / 2;
        cnt = 0;

        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cnt += min(mid, arr[i][j]);
            }
        }

        if (cnt >= half) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}