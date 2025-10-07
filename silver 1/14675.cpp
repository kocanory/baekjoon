#include <iostream>
#include <vector>

using namespace std;

int n, a, b, q;
vector<int> indeg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    indeg.assign(n + 1, 0);

   for (int i = 0;i < n - 1;i++) {
        cin >> a >> b;
        indeg[a]++;
        indeg[b]++;
    }

    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a == 1) {
            indeg[b] >= 2 ? cout << "yes\n" : cout << "no\n";
        }
        else cout << "yes\n";
    }

    return 0;
}