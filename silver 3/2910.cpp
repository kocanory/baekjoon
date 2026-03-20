#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, c;
map<int, int> m, order;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return order[a.first] < order[b.first];
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for (int i = 0, num;i < n;i++) {
        cin >> num;
        m[num]++;
        if (!order[num])
            order[num] = i + 1;
    }

    vector<pair<int, int>> arr(m.begin(), m.end());
    sort(arr.begin(), arr.end(), comp);

    for (auto [k, v] : arr) {
        for (int i = 0;i < v;i++)
            cout << k << " ";
    }

    return 0;
}