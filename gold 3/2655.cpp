#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct t {
    int width, height, weight, idx;
};

int n;
vector<t> arr;
vector<int> dp, idx;

bool cmp(t a, t b) {
    if (a.width == b.width) return a.weight > b.weight;
    return a.width > b.width;
}

int sol(int now) {
    int &ret = dp[now];
    if (ret != -1) return ret;
    ret = arr[now].height;

    for (int i = now + 1; i <= n; i++) {
        if (arr[now].weight > arr[i].weight && ret < arr[now].height + sol(i)) {
            ret = arr[now].height + sol(i);
            idx[now] = i;
        }
    }
    return ret;
}

void print(int i, int cnt) {
    if (i == 0) {
        cout << cnt << "\n";
        return;
    }
    print(idx[i], cnt + 1);
    cout << arr[i].idx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, {0,0,(int)1e9,0});
    dp.assign(n + 1, -1);
    idx.assign(n + 1, 0);

    for (int i = 1;i <= n;i++) {
        auto &[width, height, weight, num] = arr[i];
        cin >> width >> height >> weight;
        num = i;
    }

    sort(arr.begin() + 1, arr.end(), cmp);
    sol(0);
    print(idx[0], 0);
    return 0;
}