#include <iostream>
#include <queue>

using namespace std;

int a = 0, ans = 0;
string s;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0;i < s.size();i++) {
        if (s[i] == 'B') q.push(i);
        if (s[i] == 'C' && !q.empty()) {
            ans++;
            s[q.front()] = '.';
            q.pop();
        }
    }

    for (int i = 0;i < s.size();i++) {
        if (s[i] == 'A') a++;
        if (s[i] == 'B' && a) {
            a--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}