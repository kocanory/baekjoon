#include <iostream>
#include <cmath>

using namespace std;

long long k, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    while (k >= 2) {
        k -= (long long)pow(2, floor(log2(k - 1)));
        cnt++;
    }
    cout << cnt % 2;
    return 0;
}