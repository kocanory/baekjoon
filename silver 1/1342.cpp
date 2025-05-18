#include <iostream>
#include <unordered_map>

using namespace std;

string str;
int ans = 0;
unordered_map<char, int> map;

void dfs(string tmp) {
    if (tmp.length() == str.length()) {
        ans++;
        return;
    }

    for (auto [k, v] : map) {
        if (map[k] != 0 && tmp.back() != k) {
            map[k]--;
            dfs(tmp + k);
            map[k]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (auto c : str) map[c]++;

    for (auto [k, v] : map) {
        map[k]--;
        dfs(string(1, k));
        map[k]++;
    }
    cout << ans;
    return 0;
}