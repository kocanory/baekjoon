#include <iostream>

using namespace std;

int n;
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1;i <= n;i++)
        ans += n / i * i;
    cout << ans;
    return 0;
}