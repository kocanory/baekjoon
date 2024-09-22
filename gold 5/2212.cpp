#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ans;
vector<long long> s, f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    s.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> s[i];
    sort(s.begin(), s.end());

    for(int i = 1;i < n;i++) f.push_back(s[i] - s[i - 1]);
    sort(f.begin(), f.end(), greater<>());
    
    for(int i = k - 1;i < f.size();i++) ans += f[i];
    cout << ans << "\n";
    return 0;
}