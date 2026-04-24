#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
vector<int> a;
deque<int> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    a.assign(n, 0);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0, b;i < n;i++) {
        cin >> b;
        if (a[i] == 0)
            d.push_back(b);
    }

    cin >> m;
    for (int i = 0, c;i < m;i++) {
        cin >> c;
        d.push_front(c);
        cout << d.back() << " ";
        d.pop_back();
    }
    return 0;
}