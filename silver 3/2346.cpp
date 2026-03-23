#include <iostream>
#include <deque>

using namespace std;

int n;
deque<pair<int,int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1, a;i <= n;i++) {
        cin >> a;
        q.push_back({a,i});
    }

    while (true) {
        auto[now, ord] = q.front();
        q.pop_front();

        cout << ord << " ";
        if (q.empty()) break;

        if (now > 0) {
            for (int i = 0;i < now - 1;i++) {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        else {
            for (int i = 0;i < -now;i++) {
                q.push_front(q.back());
                q.pop_back();
            }
        }
    }

    return 0;
}