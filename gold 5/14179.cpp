#include <iostream>
#include <vector>

using namespace std;

int h, w, answer = 0;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    arr.assign(w, 0);

    for(int i = 0;i < w;i++) cin >> arr[i];
    for(int i = 1;i < w - 1;i++) {
        int left = arr[i], right = arr[i];
        for(int j = 0;j < i;j++) left = max(left, arr[j]);
        for(int j = w - 1;j > i;j--) right = max(right, arr[j]);
        answer += min(left, right) - arr[i];
    }
    cout << answer << "\n";
    return 0;
}