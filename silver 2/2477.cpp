#include <iostream>
#include <vector>

using namespace std;

int k, big, small;
vector<pair<int, int>> arr(12);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i = 0;i < 6;i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i + 6] = arr[i];
    }

    for (int i = 0;i < 6 + 3;i++) {
        if (arr[i].first == arr[i - 2].first && arr[i - 1].first == arr[i - 3].first) {
            big = arr[i + 1].second * arr[i + 2].second, small = arr[i - 1].second * arr[i - 2].second;
            break;
        }
    }
    cout << k * (big - small);
}