#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
string word;
map<string, int> cnt;

bool comp(pair<string, int> a, pair<string, int> b) {
    if (a.second != b.second) return a.second > b.second;
    if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> word;
        if (word.size() >= m)
            cnt[word]++;
    }

    vector<pair<string, int>> arr(cnt.begin(), cnt.end());
    sort(arr.begin(), arr.end(), comp);

    for (auto [k, v] : arr)
        cout << k << "\n";

    return 0;
}