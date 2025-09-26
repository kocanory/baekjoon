#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n, a, b, ans = 0;
unordered_map<int, vector<int>> check;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a >> b;
        check[a].push_back(b);
    }

    for (int i = n;i > 0;i--) {
        for (auto c : check[i]) pq.push(c);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}