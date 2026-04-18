#include <iostream>
#include <vector>

using namespace std;

int n, c, s, t;
long long ans = 0;
vector<pair<int, int>> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> c;
        if (c == 0) {
            if (!arr.empty()) {
                arr[arr.size() - 1].second--;
                if (arr[arr.size() - 1].second == 0) {
                    ans += arr[arr.size() - 1].first;
                    arr.pop_back();
                }
            }
        }
        else {
            cin >> s >> t;
            if (t - 1 == 0) ans += s;
            else arr.push_back({s, t - 1});
        }
    }
    cout << ans;
    return 0;
}