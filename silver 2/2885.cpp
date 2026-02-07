#include <iostream>
#include <cmath>

using namespace std;

int k, num, tmp, cnt = 0, min_num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    num = tmp = pow(2, ceil(log2(k)));

    while (k != 0) {
        if (k >= tmp) {
            min_num = cnt;
            k -= tmp;
        }
        cnt++;
        tmp /= 2;
    }
    cout << num << " " << min_num;
    return 0;
}