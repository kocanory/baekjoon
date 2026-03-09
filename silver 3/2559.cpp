#include <iostream>
#include <vector>

using namespace std;

int n, k, ans, sum = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);

    for (int i = 0;i < n;i++) cin >> arr[i];
    for (int i = 0;i < k;i++) sum += arr[i];
    ans = sum;

    for (int i = k;i < n;i++) {
        sum += arr[i] - arr[i - k];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}