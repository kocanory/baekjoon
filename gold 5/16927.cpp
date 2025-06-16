#include <iostream>
#include <vector>

using namespace std;

int n, m, r;
vector<vector<int>> arr;

void rotate(int s, int l) {
    int cnt = r % l;
    while (cnt--) {
        int start = arr[s][s];
        for (int i = s + 1; i < m - s;i++)
            arr[s][i - 1] = arr[s][i];

        for (int i = s + 1;i < n - s;i++)
            arr[i - 1][m - s - 1] = arr[i][m - s - 1];

        for (int i = m - s - 2;i >= s;i--)
            arr[n - s - 1][i + 1] = arr[n - s - 1][i];

        for (int i = n - s - 2;i >= s;i--)
            arr[i + 1][s] = arr[i][s];

        arr[s + 1][s] = start;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    arr.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int cnt = min(n, m) / 2;
    for (int i = 0;i < cnt;i++)
        rotate(i, 2 * (n - 2 * i) + 2 * (m - 2 * i) - 4);

    for (auto a : arr){
        for (auto v : a)
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}