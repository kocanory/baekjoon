#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;
vector<string> word;
vector<int> dp;

int cost(string a, string b) {
    if (a.size() != b.size()) return 1e9;
    string ta = a, tb = b;
    sort(ta.begin(), ta.end());
    sort(tb.begin(), tb.end());
    if (ta != tb) return 1e9;
    int ret = a.size();
    for (int i = 0; i < a.size(); i++)
        if (a[i] == b[i])
            ret--;
    return ret;
}

int minCost(string k) {
    int ret = 1e9;
    for (auto w : word)
        ret = min(ret, cost(k, w));
    return ret;
}

int dfs(int idx) {
    if (idx == s.size()) return 0;
    int &ret = dp[idx];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = idx;i < s.size();i++) {
        string tmp = s.substr(idx, i - idx + 1);
        int c = minCost(tmp);
        if (c == 1e9) continue;
        ret = min(ret, c + dfs(i + 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> n;
    word.assign(n, "");
    dp.assign(s.size(), -1);

    for (int i = 0;i < n;i++) cin >> word[i];

    int ans = dfs(0);
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}