#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long ans = 0;
vector<long long> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = m;i <= n;i++) ans = max(ans, arr[i] - arr[i - m]);
    cout << ans;

    return 0;
}