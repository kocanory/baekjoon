#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, k, Min, cnt, s, e;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> k;
        arr.assign(n, 0);

        for(int i = 0;i < n;i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        Min = 1e9, cnt = 0, s = 0, e = n - 1;

        while(s < e){
            int val = arr[s] + arr[e];
            if(abs(val - k) < Min){
                Min = abs(val - k);
                cnt = 1;
            }
            else if(abs(val - k) == Min)
                cnt++;

            if(val >= k) e--;
            else s++;
        }
        cout << cnt << "\n";
    }

    return 0;
}