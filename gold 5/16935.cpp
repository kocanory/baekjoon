#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, r, half_n, half_m;
vector<vector<int>> arr, temp;
vector<int> op;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    arr.assign(n, vector<int>(m));
    op.assign(r, 0);

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            cin >> arr[i][j];

    for (int i = 0;i < r;i++) cin >> op[i];

    for (auto o : op) {
        switch (o) {
            case 1:
                temp = arr;
                for (int i = 0;i < n;i++)
                    for (int j = 0;j < m;j++)
                        temp[i][j] = arr[n - i - 1][j];

                arr = temp;
                break;
            case 2:
                for (int i = 0;i < n;i++)
                    reverse(arr[i].begin(), arr[i].end());
                break;
            case 3:
                temp.assign(m, vector<int>(n));

                for (int i = 0;i < n;i++)
                    for (int j = 0;j < m;j++)
                        temp[j][n - i - 1] = arr[i][j];
                arr = temp;
                swap(n, m);
                break;
            case 4:
                temp.assign(m, vector<int>(n));

                for (int i = 0;i < n;i++)
                    for (int j = 0;j < m;j++)
                        temp[m - j - 1][i] = arr[i][j];
                arr = temp;
                swap(n, m);
                break;
            case 5:
                temp.assign(n, vector<int>(m));
                half_n = n / 2, half_m = m / 2;

                for (int i = 0;i < half_n;i++)
                    for (int j = 0;j < half_m;j++)
                        temp[i][j + half_m] = arr[i][j];

                for (int i = 0;i < half_n;i++)
                    for (int j = half_m;j < m;j++)
                        temp[i + half_n][j] = arr[i][j];

                for (int i = half_n;i < n;i++)
                    for (int j = half_m;j < m;j++)
                        temp[i][j - half_m] = arr[i][j];

                for (int i = half_n;i < n;i++)
                    for (int j = 0;j < half_m;j++)
                        temp[i - half_n][j] = arr[i][j];

                arr = temp;
                break;
            case 6:
                temp.assign(n, vector<int>(m));
                half_n = n / 2, half_m = m / 2;

                for (int i = 0;i < half_n;i++)
                    for (int j = 0;j < half_m;j++)
                        temp[i + half_n][j] = arr[i][j];

                for (int i = 0;i < half_n;i++)
                    for (int j = half_m;j < m;j++)
                        temp[i][j - half_m] = arr[i][j];

                for (int i = half_n;i < n;i++)
                    for (int j = half_m;j < m;j++)
                        temp[i - half_n][j] = arr[i][j];

                for (int i = half_n;i < n;i++)
                    for (int j = 0;j < half_m;j++)
                        temp[i][j + half_m] = arr[i][j];

                arr = temp;
                break;

        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}