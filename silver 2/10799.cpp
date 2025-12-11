#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
string s;
vector<int> b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0;i < s.size();i++) {
        if (s[i] == '(') b.push_back(i);
        else {
            b.pop_back();
            ans += s[i - 1] == '(' ? b.size() : 1;
        }
    }
    cout << ans;
    return 0;
}