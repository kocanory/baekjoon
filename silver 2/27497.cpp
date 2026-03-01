#include <iostream>
#include <deque>

using namespace std;

int n, b;
char c;
deque<char> ans;
deque<int> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> b;
        if (b == 3) {
            if (!stk.empty()) {
                if (stk.back() == 1) ans.pop_back();
                else ans.pop_front();
                stk.pop_back();
            }
        }
        else {
            cin >> c;
            if (b == 1) ans.push_back(c);
            else ans.push_front(c);
            stk.push_back(b);
        }
    }

    if (stk.empty()) cout << 0;
    else {
        for (auto a : ans)
            cout << a;
    }
    return 0;
}