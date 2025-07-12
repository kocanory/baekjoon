#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int a = 1; a < n;a++) {
        int b = n - a;
        if (a * b < k) continue;
        vector<int> pos_a(b + 1);
        for (int i = 0;i < a;i++) {
            int cnt = min(b, k);
            pos_a[b - cnt]++;
            k -= cnt;
        }
        for (int i = 0;i <= b;i++) {
            for (int j = 0;j < pos_a[i];j++)
                cout << 'A';
            if (i < b)
                cout << 'B';
        }
        return 0;
    }
    cout << -1;
    return 0;
}