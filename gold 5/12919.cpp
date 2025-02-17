#include <iostream>
#include <algorithm>

using namespace std;

string s, t;
bool flag = false;

void dfs(string now) {
    if (now.length() == s.length()) {
        if (now == s)
            flag = true;
        return;
    }
    if (now.back() == 'A') dfs(now.substr(0, now.length() - 2));
    if (now.front() == 'B') {
        now = now.substr(1, now.length() - 1);
        reverse(now.begin(), now.end());
        dfs(now);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> t;
    dfs(t);
    cout << flag << "\n";
    return 0;
}