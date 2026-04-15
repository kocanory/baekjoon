#include <iostream>
#include <vector>

using namespace std;

int n, i, j;
vector<int> arr;

void check() {
    i = n - 1;
    while (i > 0 && arr[i - 1] < arr[i]) i--;

    if (i == 0) {
        cout << -1;
        return;
    }

    j = n - 1;
    while (arr[i - 1] < arr[j]) j--;
    swap(arr[i - 1], arr[j]);

    j = n - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++; j--;
    }

    for (int a : arr) cout << a << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int &a : arr) cin >> a;

    check();

    return 0;
}