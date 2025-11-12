#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans, cur;
vector<int> arr, sorted_arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ans = n, cur = n - 1;
    arr.assign(n, 0);

    for(auto &a : arr) cin >> a;
    sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    for(int i = n - 1;i >= 0;i--)
        if(arr[i] == sorted_arr[cur]){
            ans--;
            cur--;
        }
    cout << ans;
    return 0;
}