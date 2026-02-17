#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string s, t;
int pos, pt = 0, ps = 0, ans = 1;
map<char, vector<int>> alpha;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> t;
    for (int i = 0; i < t.size();i++)
        alpha[t[i]].push_back(i);

    while (ps < s.size()) {
        if (alpha[s[ps]].empty()) {
            ans = -1;
            break;
        }

        pos = lower_bound(alpha[s[ps]].begin(), alpha[s[ps]].end(), pt) - alpha[s[ps]].begin();
        if (pos >= alpha[s[ps]].size()) {
            ans++;
            pos = 0;
        }
        pt = alpha[s[ps]][pos] + 1;
        ps++;
    }
    cout << ans;
}