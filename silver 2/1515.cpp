#include <iostream>

using namespace std;

string n;
int idx = 0, ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (true) {
        for (auto a : to_string(ans)) {
            if (n[idx] == a)
                idx++;
        }
        if (idx >= n.size()) {
            cout << ans;
            break;
        }
        ans++;
    }
    return 0;
}