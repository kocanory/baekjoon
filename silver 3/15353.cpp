#include <iostream>

using namespace std;

string a, b;

string calc() {
    string res = "";
    int flag = 0;
    a.size() > b.size() ? b = string(a.size() - b.size(), '0') + b : a = string(b.size() - a.size(), '0') + a;

    for (int i = a.size() - 1;i >= 0; i--) {
        int val = (a[i] - '0' + b[i] - '0') + flag;
        res = char(val % 10 + '0') + res;
        flag = val / 10;
    }
    if (flag) res = '1' + res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << calc();
    return 0;
}