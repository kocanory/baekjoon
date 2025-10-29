#include <iostream>
#include <vector>

using namespace std;

int n, m, u, v;
vector<int> arr, check;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n + 1, 0);
    check.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) arr[i] = i;

    while (m--) {
        cin >> u >> v;
        arr[u]++;
        arr[v]--;
    }

    for (int i = 1;i <= n;i++) {
        if (check[arr[i]]) {
            cout << -1;
            exit(0);
        }
        check[arr[i]] = true;
    }
    for (int i = 1;i <= n;i++) cout << arr[i] << " ";
    return 0;
}