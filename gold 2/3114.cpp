#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r, c;
string str;
vector<vector<vector<int>>> arr;
vector<vector<int>> dp, ap, ba;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    arr.assign(2, vector(r, vector(c, 0)));
    dp.assign(r, vector(c, 0));
    ap.assign(r, vector(c, 0));
    ba.assign(r, vector(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0, f, v; j < c; j++) {
            cin >> str;
            f = str[0] - 'A', v = stoi(str.substr(1));
            arr[f][i][j] = v;
            if (f) ba[i][j] = v;
            else ap[i][j] = v;
        }
    }

    for (int j = 0; j < c; j++) {
        for (int i = 1; i < r; i++) {
            ap[i][j] += ap[i - 1][j];
            ba[i][j] += ba[i - 1][j];
        }
    }

    for (int i = 0; i < r; i++) dp[i][0] = ap[r - 1][0] - ap[i][0];
    for (int j = 1; j < c; j++) dp[0][j] = dp[0][j - 1] + ap[r - 1][j] - ap[0][j];

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]) + ba[i - 1][j] + ap[r - 1][j] - ap[i][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - arr[0][i][j]);
        }
    }
    cout << dp[r - 1][c - 1];
}