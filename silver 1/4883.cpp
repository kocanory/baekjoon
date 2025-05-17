#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 1;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n) {
        arr.assign(n, vector<int>(3));

        for (int i = 0;i < n;i++)
            for (int j = 0;j < 3;j++)
                cin >> arr[i][j];

        arr[1][0] += arr[0][1];
        arr[1][1] += min(arr[0][1], min(arr[0][1]+ arr[0][2], arr[1][0]));
        arr[1][2] += min(arr[0][1], min(arr[0][1] + arr[0][2], arr[1][1]));

        for (int i = 2;i < n;i++) {
            arr[i][0] += min(arr[i - 1][0], arr[i - 1][1]);
            arr[i][1] += min(arr[i - 1][0], min(arr[i - 1][1], min(arr[i - 1][2], arr[i][0])));
            arr[i][2] += min(arr[i - 1][1], min(arr[i - 1][2], arr[i][1]));
        }

        cout << cnt << ". " << arr[n - 1][1] << "\n";
        cnt++;
        cin >> n;
    }

    return 0;
}