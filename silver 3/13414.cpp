#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int k, l;
string s;
unordered_map<string, int> idx;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> l;
    for (int i = 0;i < l;i++) {
        cin >> s;
        idx[s] = i + 1;
    }

    vector<pair<string, int>> arr(idx.begin(), idx.end());
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0;i < min((int)arr.size(), k);i++)
        cout << arr[i].first << "\n";
    return 0;
}