#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> arr, op(4);
long long Max = LLONG_MIN, Min = LLONG_MAX;

void dfs(int idx, long long val, int add, int sub, int mul, int div) {
    if (idx == n) {
        Max = max(Max, val);
        Min = min(Min, val);
        return;
    }
    if (add) dfs(idx + 1, val + arr[idx], add - 1, sub, mul, div);
    if (sub) dfs(idx + 1, val - arr[idx], add, sub - 1, mul, div);
    if (mul) dfs(idx + 1, val * arr[idx], add, sub, mul - 1, div);
    if (div) dfs(idx + 1, val / arr[idx], add, sub, mul, div - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;
    for (int &o : op) cin >> o;

    dfs(1, arr[0], op[0], op[1], op[2], op[3]);
    cout << Max << "\n" << Min;
    return 0;
}