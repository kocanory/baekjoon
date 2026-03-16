#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt = 0, ans = -1;
vector<int> arr;

void merge(int l, int m, int r) {
    int i = l, j = m + 1;
    vector<int> tmp;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            tmp.push_back(arr[i++]);
        else
            tmp.push_back(arr[j++]);
    }

    while (i <= m)
        tmp.push_back(arr[i++]);
    while (j <= r)
        tmp.push_back(arr[j++]);

    i = l;
    int t = 0;
    while (i <= r) {
        if (++cnt == k) ans = tmp[t];
        arr[i++] = tmp[t++];
    }
}

void merge_sort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(l, m);
        merge_sort(m + 1, r);
        merge(l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;

    merge_sort(0, n - 1);
    cout << ans;

    return 0;
}