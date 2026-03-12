#include <iostream>

using namespace std;

string s, tmp = "";
bool flag = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);

    for (auto c : s) {
        if (c == '<') {
            if (!tmp.empty()) {
                for (int t = tmp.size() - 1; t >= 0; --t)
                    cout << tmp[t];
                tmp.clear();
            }
            tmp += c;
            flag = true;
        }
        else if (c == '>') {
            tmp += c;
            for (auto t : tmp)
                cout << t;
            tmp.clear();
            flag = false;
        }
        else if (!flag && c == ' ') {
            for (int t = tmp.size() - 1; t >= 0; --t)
                cout << tmp[t];
            cout << ' ';
            tmp.clear();
        }
        else tmp += c;
    }
    if (!tmp.empty())
        for (int t = tmp.size() - 1; t >= 0; --t)
            cout << tmp[t];
    return 0;
}