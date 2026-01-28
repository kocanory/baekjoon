#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int p, m, l, num;
string n;
vector<vector<pair<int, string>>> room(300);

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> m;

    for (int i = 0;i < p;i++) {
        cin >> l >> n;
        num = 0;
        while (true) {
            if (room[num].empty() || (room[num].size() < m && abs(room[num][0].first - l) <= 10))
                break;
            num++;
        }
        room[num].push_back({l, n});
    }

    for (auto &r : room) {
        if (!r.empty()) {
            cout << (r.size() == m ? "Started!" : "Waiting!") << "\n";
            sort(r.begin(), r.end(), comp);
            for (auto [l, n] : r) {
                cout << l << " " << n << "\n";
            }
        }
    }

}