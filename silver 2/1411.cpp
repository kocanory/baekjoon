#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, ans = 0;
vector<string> arr, total;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, "");

    for (auto &a : arr) cin >> a;

    for (auto a : arr) {
        int cnt = 0;
        map<char, int> alpha, num;
        string t;

        for (auto v : a) {
            if (!alpha[v]) {
                alpha[v] = true;
                num[v] = cnt++;
                t += to_string(cnt);
            }
            else t += to_string(num[v]);
        }
        total.push_back(t);
    }
    for (int i = 0;i < n;i++)
        for (int j = 0;j < i;j++)
            if (total[i] == total[j])
                ans++;

    cout << ans;
    return 0;
}