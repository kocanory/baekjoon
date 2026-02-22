#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> arr(10), vec;

void dfs(int idx, int score) {
    if (idx == 10) {
        if (score >= 5)
            ans++;
        return;
    }

    for (int i = 1;i <= 5;i++) {
        if (idx >= 2 && vec[idx - 1] == i && vec[idx - 2] == i) continue;
        vec.push_back(i);
        i == arr[idx] ? dfs(idx + 1, score + 1) : dfs(idx + 1, score);
        vec.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int &a : arr) cin >> a;
    dfs(0, 0);
    cout << ans;
}