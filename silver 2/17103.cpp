#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector check(1000001, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2;i <= 1000000;i++) {
        if (check[i])
            for (int j = 2 * i;j <= 1000000;j += i)
                check[j] = false;
    }

    cin >> t;
    while (t--) {
        cin >> n;

        int cnt = 0;
        for (int i = 2;i <= n / 2;i++)
            if (check[i] && check[n - i])
                cnt++;
        cout << cnt << "\n";
    }

    return 0;
}