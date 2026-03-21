#include <iostream>

using namespace std;

int n, num, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n) {
        num = 1, cnt = 1;

        while (num % n) {
            num = num * 10 + 1;
            cnt++;
            num %= n;
        }
        cout << cnt << "\n";
    }

    return 0;
}