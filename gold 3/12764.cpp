#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k = 0;
vector<pair<int, int>> arr;
vector<int> check;
priority_queue<pair<int, int>> t;
priority_queue<int> seat;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, {0, 0});
    for (auto &[a, b] : arr) cin >> a >> b;

    sort(arr.begin(), arr.end());

    for (auto [s, e] : arr) {
        while (!t.empty() && -t.top().first <= s) {
            auto [b, r] = t.top(); t.pop();
            seat.push(-r);
        }

        if (seat.empty()) {
            t.push({-e, k});
            check.push_back(1);
            k++;
        }
        else {
            int r = -seat.top(); seat.pop();
            check[r]++;
            t.push({-e, r});
        }
    }
    cout << k << "\n";
    for (auto c : check) cout << c << " ";
    return 0;
}