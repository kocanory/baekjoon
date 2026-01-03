#include <iostream>

using namespace std;

string str;

bool check(string s) {
    for (int i = 0;i < s.length() / 2;i++) {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (int i = 0;i < str.length();i++) {
        string tmp = str.substr(i, str.length() - i);
        if (check(tmp)) {
            cout << str.length() + i;
            break;
        }
    }
    return 0;
}