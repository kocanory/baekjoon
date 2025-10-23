#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b;
vector<int> p, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> a >> b;
        p.push_back(a + b);
        m.push_back(a - b);
    }
    sort(p.begin(), p.end());
    sort(m.begin(), m.end());
    cout << max(p.back() - p[0], m.back() - m[0]);
    return 0;
}