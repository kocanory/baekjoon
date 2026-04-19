#include <iostream>

using namespace std;

int n, idx;
string p, p1, p2, f, ex;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> p;
    idx = p.find('*');
    p1 = p.substr(0, idx), p2 = p.substr(idx + 1);

    while (n--) {
        cin >> f;
        if (p1.size() + p2.size() > f.size()) cout << "NE\n";
        else if (f.find(p1) == 0) {
            if (f.substr(f.size() - p2.size()) == p2) cout << "DA\n";
            else cout << "NE\n";
        }
        else cout << "NE\n";
    }

    return 0;
}