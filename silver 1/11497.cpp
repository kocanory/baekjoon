#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n, 0);
        
        for(int i = 0;i < n;i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        ans = max(ans, arr[1] - arr[0]);
        ans = max(ans, arr[n - 1] - arr[n - 2]);
        
        for(int i = 0;i < n - 2;i++)
            ans = max(ans, arr[i + 2] - arr[i]);
        cout << ans << "\n";
    }

    return 0;
}