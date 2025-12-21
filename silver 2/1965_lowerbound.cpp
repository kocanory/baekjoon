#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (auto &a : arr) {
        cin >> a;
        if (lis.empty() || lis.back() < a) lis.push_back(a);
        else {
            auto pos = lower_bound(lis.begin(), lis.end(), a);
            *pos = a;
        }
    }
    cout << lis.size();
    return 0;
}