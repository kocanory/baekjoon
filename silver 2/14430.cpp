#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n + 1, vector(m + 1, 0));

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            cin >> arr[i][j];

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);

    cout << arr[n][m];
}