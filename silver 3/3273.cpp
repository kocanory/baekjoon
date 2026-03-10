#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, x, l = 0, r, ans = 0;
vector<long long> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    r = n - 1;

    for (int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cin >> x;


    while (l < r) {
        if (arr[l] + arr[r] <= x) {
            if (arr[l] + arr[r] == x) ans++;
            l++;
        }
        else r--;
    }
    cout << ans;
    return 0;
}