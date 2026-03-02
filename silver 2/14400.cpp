#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, mid;
long long ans = 0;
vector<int> x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    x.assign(n, 0);
    y.assign(n, 0);

    for (int i = 0;i < n;i++)
        cin >> x[i] >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    mid = n / 2;

    for (int i = 0;i < n;i++)
        ans += abs(x[i] - x[mid])  + abs(y[i] - y[mid]);

    cout << ans;
    return 0;
}