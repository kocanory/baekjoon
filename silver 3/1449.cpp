#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, now, ans = 1;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    arr.assign(n, 0);

    for (int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    now = arr[0];

    for (int i = 1;i < n;i++) {
        if (arr[i] - now >= l) {
            now = arr[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}