#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> s;
        vector<char> f, e;

        for (auto c : s) {
            if (c == '<') {
                if (!f.empty()) {
                    char tmp = f.back();
                    f.pop_back();
                    e.push_back(tmp);
                }
            }
            else if (c == '>') {
                if (!e.empty()) {
                    char tmp = e.back();
                    e.pop_back();
                    f.push_back(tmp);
                }
            }
            else if (c == '-') {
                if (!f.empty())
                    f.pop_back();
            }
            else
                f.push_back(c);
        }

        reverse(e.begin(), e.end());
        f.insert(f.end(), e.begin(), e.end());
        for (auto c : f)
            cout << c;
        cout << "\n";
    }

    return 0;
}