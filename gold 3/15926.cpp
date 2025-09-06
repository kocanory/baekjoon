#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0, cnt = 0;
string s;
vector<int> dp, stack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    dp.assign(n, 0);

    for (int i = 0;i < n;i++) {
        if (s[i] == '(') stack.push_back(i);
        else {
            if (!stack.empty()) {
                dp[i] = dp[stack.back()] = 1;
                stack.pop_back();
            }
        }
    }

    for (auto d : dp) {
        if (d) {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 0;
    }
    cout << ans;
    return 0;
}