#include <iostream>

using namespace std;

int a, k, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> k;

    while (a < k) {
        if (k % 2 == 0 && k / 2 >= a) k /= 2;
        else k--;
        ans++;
    }

    cout << ans;

    return 0;
}