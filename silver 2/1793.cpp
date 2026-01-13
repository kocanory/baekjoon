#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> dp(251, "0");

string add (string a, string b) {
    string res;
    bool flag = 0;

    if (a.size() > b.size()) b = string(a.size() - b.size(), '0') + b;
    else a = string(b.size() - a.size(), '0') + a;

    for (int i = a.size() - 1;i >= 0;i--) {
        int val = (a[i] - '0') + (b[i] - '0') + flag;
        flag = val / 10, val = val % 10;
        res = to_string(val) + res;
    }

    if (flag) res = "1" + res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0] = "1", dp[1] = "1";

    for (int i = 2;i <= 250;i++) {
        dp[i] = add(add(dp[i - 1], dp[i - 2]),dp[i - 2]);
    }

    while (cin >> n) 
        cout << dp[n] << "\n";
    
    return 0;
}