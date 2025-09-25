#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, m, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> m;
        vector<int> ans;
        priority_queue<int> up;
        priority_queue<int, vector<int>, greater<>>down;
        for (int i = 1;i <= m;i++) {
            cin >> n;
            if (i % 2) {
                up.push(n);
                if (!up.empty() && !down.empty()) {
                    if (up.top() > down.top()) {
                        down.push(up.top());
                        up.pop();
                        up.push(down.top());
                        down.pop();
                    }
                }
                ans.push_back(up.top());
            }
            else down.push(n);
        }
        cout << ans.size() << "\n";
        for (auto a : ans) cout << a << " ";
        cout << "\n";
    }

    return 0;
}