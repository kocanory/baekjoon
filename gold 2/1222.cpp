#include <iostream>
#include <vector>

using namespace std;

long long n, Max = 0, ans = 0, cnt;
vector<long long> arr, check(2000001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (auto &a : arr) {
        cin >> a;
        Max = max(Max, a);
        check[a]++;
    }

    ans = n;
    for (int i = 2;i <= Max;i++) {
        cnt = 0;
        for (int j = i;j <= Max;j += i)
            cnt += check[j];
        if (cnt > 1) ans = max(ans, i * cnt);
    }
    cout << ans;
}