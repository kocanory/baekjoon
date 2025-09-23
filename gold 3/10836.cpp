#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    cnt.assign(2 * m + 1, 0);

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = a;i < a + b;i++) cnt[i]++;
        for (int i = a + b;i < a + b + c;i++) cnt[i] += 2;
    }

    for (int i = 0;i < m;i++) {
        for (int j = 0;j < m;j++)
            cout << (j == 0 ? 1 + cnt[(m - 1) - i] : 1 + cnt[(m - 1) + j]) << " ";
        cout << "\n";
    }
    return 0;
}