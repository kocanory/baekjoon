#include <iostream>
#include <vector>
#include <map>

using namespace std;

int s, p, ans;
string d;
vector<int> c(4);
map<char, int> idx = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

bool check() {
    for (auto v : c)
        if (v > 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> p >> d;
    for (auto &v : c) cin >> v;

    for (int i = 0;i < p;i++)
        c[idx[d[i]]]--;
    if (check()) ans++;

    for (int i = p;i < s;i++) {
        c[idx[d[i]]]--;
        c[idx[d[i - p]]]++;
        if (check()) ans++;
    }
    cout << ans;
    return 0;
}