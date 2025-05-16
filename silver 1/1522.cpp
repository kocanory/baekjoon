#include <iostream>

using namespace std;

string s;
int aCnt = 0, ans = 1000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (auto c : s)
        if (c == 'a')
            aCnt++;

    for (int i = 0;i < s.length();i++) {
        int bCnt = 0;
        for (int j = i; j < i + aCnt;j++)
            if (s[j % s.length()] == 'b')
                bCnt++;

        ans = min(ans, bCnt);
    }
    cout << ans;
    return 0;
}