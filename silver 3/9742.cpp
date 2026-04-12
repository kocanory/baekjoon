#include <iostream>
#include <vector>

using namespace std;

string str;
int n, m, cnt;
vector<bool> check;

void dfs(int seq, string now) {
    if (seq == str.size()) {
        cnt++;
        if (cnt == n) {
            cout << str << " " << n << " = " << now << "\n";
        }
        return;
    }

    for (int i = 0;i < str.size();i++) {
        if (!check[i]) {
            check[i] = true;
            dfs(seq + 1, now + str[i]);
            check[i] = false;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> str >> n;
        if (cin.eof()) break;

        m = 1;
        for (int i = str.size();i > 1;i--)
            m *= i;

        if (m < n) {
            cout << str << " " << n << " = No permutation\n";
            continue;
        }
        cnt = 0;
        check.assign(str.size(), false);
        dfs(0, "");
   
    }
    return 0;
}