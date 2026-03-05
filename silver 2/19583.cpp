#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

string s_str, e_str, q_str, t_str, n;
int s, e, q, ans = 0;
map<string, bool> attend;

int convert(string t) {
    stringstream ss(t);
    vector<int> v;
    while (getline(ss, t, ':'))
        v.push_back(stoi(t));

    return v[0] * 60 + v[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s_str >> e_str >> q_str;
    s = convert(s_str), e = convert(e_str), q = convert(q_str);

    while (true) {
        cin >> t_str >> n;
        if (cin.eof()) break;
        int t = convert(t_str);

        if (t <= s) attend[n] = true;
        if (e <= t && t <= q && attend[n]) {
            ans++;
            attend.erase(n);
        }
    }
    cout << ans;
    return 0;
}