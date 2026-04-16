#include <iostream>
#include <vector>

using namespace std;

string var;

bool checkErr() {
    bool under = false, upper = false;

    for (auto v : var) {
        if (v == '_') under = true;
        else if (isupper(v)) upper = true;
    }

    if (under && upper) return true;
    if (var[0] == '_' || isupper(var[0])) return true;
    if (var.back() == '_') return true;
    for (int i = 0;i < var.size() - 1;i++)
        if (var[i] == '_' && var[i + 1] == '_') return true;
    return false;
}

bool checkJava() {
    for (auto v : var)
        if (isupper(v))
            return true;
    return false;
}

bool checkCpp() {
    for (auto v : var)
        if (v == '_')
            return true;
    return false;
}

void conv() {
    string tmp = "";
    vector<string> res;

    if (checkJava()) {
        for (auto v : var) {
            if (isupper(v)) {
                res.push_back(tmp);
                tmp.clear();
                tmp += tolower(v);
            }
            else tmp += v;
        }
        if (!tmp.empty()) res.push_back(tmp);
        for (int i = 0;i < res.size();i++) {
            cout << res[i];
            if (i < res.size() - 1) cout << "_";
        }
    }
    else if (checkCpp()) {
        for (auto v : var) {
            if (v == '_') {
                res.push_back(tmp);
                tmp.clear();
            }
            else tmp += v;
        }
        if (!tmp.empty()) res.push_back(tmp);
        for (int i = 0;i < res.size();i++) {
            if (i) res[i][0] = toupper(res[i][0]);
            cout << res[i];
        }
    }
    else cout << var;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> var;

    if (checkErr()) cout << "Error!";
    else conv();
    return 0;
}