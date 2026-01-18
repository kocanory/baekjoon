#include <iostream>
#include <vector>

using namespace std;

int n, s, ans = 0;
vector<int> arr, check;

void dfs(int now) {
    check[now] = true;
    ans++;

    if (now + arr[now] < n && !check[now + arr[now]]) dfs(now + arr[now]);
    if (now - arr[now] >= 0 && !check[now - arr[now]]) dfs(now - arr[now]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    check = arr;

    for (int &a : arr) cin >> a;
    cin >> s;

    dfs(s - 1);
    cout << ans;
    return 0;
}