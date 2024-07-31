#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> Max(3), Min(3);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0;i < n;i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(i == 0) {
            Max[0] = a; Max[1] = b; Max[2] = c;
            Min[0] = a; Min[1] = b; Min[2] = c;
        }
        else {
            int ma = Max[0], mb = Max[1], mc = Max[2];
            Max[0] = max(ma, mb) + a; Max[1] = max(max(ma, mb), mc) + b; Max[2] = max(mb, mc) + c;

            ma = Min[0], mb = Min[1], mc = Min[2];
            Min[0] = min(ma, mb) + a; Min[1] = min(min(ma, mb), mc) + b; Min[2] = min(mb, mc) + c;
        }
    }

    cout << *max_element(Max.begin(), Max.end()) << " " << *min_element(Min.begin(), Min.end());
}