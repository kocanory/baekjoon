#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1, cnt;
vector<string> arr;

void check() {
    for (int i = 0;i < n;i++) {
        cnt = 1;
        for (int j = 1;j < n;j++) {
            if (arr[i][j] == arr[i][j - 1]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else 
                cnt = 1;
        }
    }

    for (int j = 0;j < n;j++) {
        cnt = 1;
        for (int i = 1;i < n;i++) {
            if (arr[i][j] == arr[i - 1][j]) {
                cnt++;
                ans = max(ans, cnt);
            }
            else 
                cnt = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n + 1, "");

    for (int i = 0;i <n;i++) cin >> arr[i];

    for (int i = 0;i < n;i++)
        for (int j = 1;j < n;j++)
            if (arr[i][j] != arr[i][j - 1]) {
                swap(arr[i][j], arr[i][j - 1]);
                check();
                swap(arr[i][j], arr[i][j - 1]);
            }

    for (int j = 0;j <n;j++)
        for (int i = 1;i < n;i++)
            if (arr[i][j] != arr[i - 1][j]) {
                swap(arr[i][j], arr[i - 1][j]);
                check();
                swap(arr[i][j], arr[i - 1][j]);
            }
    cout << ans;
    return 0;
}