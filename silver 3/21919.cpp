#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int n;
long long g, ans;
vector<int> arr, vec, check(1000001, true);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2;i <= 1000000;i++) {
        if (!check[i]) continue;
        for (int j = 2 * i;j <= 1000000;j += i)
            check[j] = false;
    }

    cin >> n;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;

    for (auto a : arr)
        if (check[a])
            vec.push_back(a);

    if (vec.empty()) {
        cout << -1;
        exit(0);
    }
    
    g = vec[0];
    for (int i = 1;i < vec.size();i++)
        g = gcd(g, vec[i]);

    ans = g;
    for (auto v : vec)
        ans *= v / g;
    cout << ans;
    
    return 0;
}