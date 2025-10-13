#include <iostream>
#include <vector>

using namespace std;

int n, m, l, r = 0, ans = 0;
vector<int> arr, group;

int search(int mid) {
    int sum = 0, cnt = 0;
    for (auto a : arr) {
        sum += a;
        if (sum > mid) {
            sum = a;
            cnt++;
        }
    }
    if (sum) cnt++;
    return cnt;
}

void make() {
    int sum = 0, cnt = 0, gCnt = m;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
        if (sum > ans) {
            sum = arr[i];
            group.push_back(cnt);
            cnt = 0;
            gCnt--;
        }
        cnt++;

        if (gCnt == n - i) {
            group.push_back(cnt);
            for (int j = n - i - 1;j > 0;j--)
                group.push_back(1);
            return;
        }
    }
    if (sum) group.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        l = max(arr[i], l);
        r += arr[i];
    }

    while (l <= r) {
        int mid = (l + r) / 2, cnt = search(mid);

        if (cnt > m)
            l = mid + 1;
        else {
            r = mid - 1;
            ans = mid;
        }
    }

    cout << ans << "\n";
    make();
    for (auto g : group)
        cout << g << " ";
    return 0;
}