#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> arr;
int total = 0, price = 0, ans = 2147483647, flag = 0;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, {0, 0});

    for (auto &[a, b] : arr) cin >> a >> b;
    sort(arr.begin(), arr.end(), comp);

    for (int i = 0;i < n;i++) {
        total += arr[i].first;
        if (i && arr[i].second == arr[i - 1].second) price += arr[i].second;
        else price = 0;
        if (total >= m) {
            ans = min(ans, price + arr[i].second);
            flag = 1;
        }
    }
    cout << (flag ? ans : -1);
    return 0;
}