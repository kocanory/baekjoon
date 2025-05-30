#include <iostream>

using namespace std;

int t, n;

bool check(string str) {
    int sum = 0, num = 0;
    char sign = '+';

    for (auto c : str) {
        if (c >= '1' && c <= '9')
            num = num * 10 + (c - '0');
        else if (c == '+' || c == '-') {
            if (sign == '+')
                sum += num;
            else
                sum -= num;
            num = 0;
            sign = c;
        }
    }
    if (sign == '+')
        sum += num;
    else
        sum -= num;
    return sum == 0;
}

void dfs(int num, string str) {
    if (num > n) {
        if (check(str))
            cout << str << "\n";
        return;
    }
    dfs(num + 1, str + " " + to_string(num));
    dfs(num + 1, str + "+" + to_string(num));
    dfs(num + 1, str + "-" + to_string(num));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;
        dfs(2, "1");
        cout << "\n";
    }

    return 0;
}