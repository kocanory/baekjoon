#include <iostream>
#include <vector>

using namespace std;

int r, c, q, r1, c1, r2, c2;
vector<vector<int>> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> q;
    arr.assign(r + 1, vector(c + 1, 0));

    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++)
            cin >> arr[i][j];

    for(int i = 1;i <= r;i++)
        for (int j = 2;j <= c;j++)
            arr[i][j] += arr[i][j - 1];

    for(int j = 1;j <= c;j++)
        for(int i = 2;i <= r;i++)
            arr[i][j] += arr[i - 1][j];

    while(q--){
        cin >> r1 >> c1 >> r2 >> c2;
        int sum = arr[r2][c2] - arr[r2][c1 - 1] - arr[r1 - 1][c2] + arr[r1 - 1][c1 - 1];
        cout << sum / ((r2 - r1 + 1) * (c2 - c1 + 1)) << "\n";
    }

    return 0;
}