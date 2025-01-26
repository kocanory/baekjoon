#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, vector<int>(n));

    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> arr[i][j];

    for (int k = 0;k < n;k++)
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}