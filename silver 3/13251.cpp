#include <iostream>
#include <vector>

using namespace std;

int n, k, total = 0;
vector<int> arr;
double ans = 0, val;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int &a : arr) {
        cin >> a;
        total += a;
    }
    cin >> k;

    for (int &a : arr) {
        if (a < k) continue;
        val = 1;
        for (int j = 0; j < k; j++)
            val *= (a - j) / double(total - j);
        ans += val;
    }

    cout << fixed;
    cout.precision(15);
    cout << ans;
    return 0;
}