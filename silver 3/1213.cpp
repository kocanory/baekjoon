#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string s, ans = "", tmp = "";
char mid;
map<char, int> check;
int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (auto c : s) check[c]++;

    for (auto [k, v] : check) {
        if (v % 2) {
            cnt++;
            mid = k;
        }
    }

    if (cnt > 1) {
        cout << "I'm Sorry Hansoo";
        exit(0);
    }

    for (auto [k, v] : check)
        ans += string(v / 2, k);

    tmp = ans;
    reverse(tmp.begin(), tmp.end());
    if (cnt) ans += mid + tmp;
    else ans += tmp;

    cout << ans;
    return 0;
}