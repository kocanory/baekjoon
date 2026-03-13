#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> check, tmp;

void dfs(int cnt) {
    if (cnt == n) {
        for (auto t : tmp)
            cout << t << " ";
        cout << "\n";
        return;
    }

    for (int i = 1;i <= n;i++) {
        if (!check[i]) {
            check[i] = true;
            tmp.push_back(i);
            dfs(cnt + 1);
            tmp.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    check.assign(n + 1, 0);

    dfs(0);

    return 0;
}