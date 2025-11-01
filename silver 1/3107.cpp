#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string addr, s;
vector<string> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> addr;
    stringstream ss(addr);

    while (getline(ss, s, ':'))
        a.push_back(s);

    if (a.size() != 8) {
        vector<string> tmp;
        bool flag = true;
        for (auto ad : a) {
            if (ad.size() == 0 && flag) {
                for (int i = 0;i < 9 - a.size();i++)
                    tmp.push_back("0000");
                flag = false;
            }
            else tmp.push_back(ad);
        }
        a = tmp;
    }
    for (int i = 0;i < a.size(); i++) {
        a[i] = string(4 - a[i].size(), '0') + a[i];
        cout << a[i];
        if (i < a.size() - 1) cout << ':';
    }
    return 0;
}