#include <iostream>
#include <vector>

using namespace std;

int n, f;
int combi[11][11];
bool check[11];
vector<int> v;

void solve(int cnt, int sum) {
    if (cnt == n) {
        if (sum == f) {
            for (auto a : v) cout << a << ' ';
            exit(0);
        }
        return;
    }
    for (int i = 1;i <= n;i++) {
        if (!check[i]) {
            check[i] = true;
            v.push_back(i);
            solve(cnt + 1, sum + i * combi[n - 1][cnt]);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> f;

    for (int i = 0;i <= n;i++) {
        combi[i][0] = combi[i][i] = 1;
        for (int j = 1;j < i;j++)
            combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
    }

    solve(0, 0);
    return 0;
}