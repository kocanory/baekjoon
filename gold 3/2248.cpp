#include <iostream>
#include <vector>

using namespace std;

int N, L;
long long I;
string ans = "";
vector<vector<int>> combi;

void dfs(int n, int l, long long i) {
    if (n == 0) return;
    if (l == 0) {
        ans += string(n, '0');
        return;
    }
    long long skip = 0;
    for (int c = 0;c <= l;c++)
        skip += combi[n - 1][c];

    if (skip >= i) {
        ans += '0';
        dfs(n - 1, l, i);
    }
    else {
        ans += '1';
        dfs(n - 1, l - 1, i - skip);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> I;
    combi = vector(N + 1, vector(N + 1, 0));
    combi[0][0] = 1, combi[1][0] = 1, combi[1][1] = 1;

    for (int i = 2;i <= N;i++) {
        combi[i][0] = 1;
        for (int j = 1;j <= i;j++)
            combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
    }

    dfs(N, L, I);
    cout << ans;
}