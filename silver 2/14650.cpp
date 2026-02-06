#include <iostream>

using namespace std;

int n, ans = 0;

void dfs(int val, int cnt) {
    if (cnt == n) {
        if (val % 3 == 0)
            ans++;
        return;
    }

    if (cnt != 0)
        dfs(val, cnt + 1);
    dfs(val + 1, cnt + 1);
    dfs(val + 2, cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dfs(0, 0);

    cout << ans;
    return 0;
}