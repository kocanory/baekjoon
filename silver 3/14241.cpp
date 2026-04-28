#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;
    sort(arr.begin(), arr.end());

    for (int i = 1, back = arr[0];i < n;i++) {
        ans += back * arr[i];
        back += arr[i];
    }
    cout << ans;
    return 0;
}