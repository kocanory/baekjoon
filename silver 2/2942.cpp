#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <tuple>

using namespace std;

int r, g, n;
vector<tuple<int, int, int>> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> g;
    n = gcd(r, g);

    for (int i = 1;i <= sqrt(n);i++) {
        if (n % i == 0) {
            ans.push_back({i, r / i, g / i});
            if (i != n / i) {
                ans.push_back({n / i, r / (n / i), g / (n / i)});
            }
        }
    }

    for (auto [a, b, c] : ans)
        cout << a << " " << b << " " << c << "\n";
    return 0;
}