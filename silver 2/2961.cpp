#include <iostream>
#include <vector>

using namespace std;

int n, ans = (int)1e9;
vector<pair<int, int>> arr;

void dfs(int idx, int s, int b) {
    for (int i = idx;i < n;i++) {
        auto [ns, nb] = arr[i];
        ans = min(ans, abs(s * ns - (b + nb)));
        dfs(i + 1, s * ns, b + nb);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, {0, 0});

    for (auto &[s, b] : arr) cin >> s >> b;
    dfs(0, 1, 0);

    cout << ans;

    return 0;
}