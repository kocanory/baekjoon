#include <iostream>
#include <queue>

using namespace std;

int n, m;
long long ans;
priority_queue<long long, vector<long long>, greater<>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while (n--) {
        int a;
        cin >> a;
        pq.push(a);
    }

    while (m--) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";
    return 0;
}