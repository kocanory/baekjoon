#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 2e9, s = 0, e = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    while(s < n && e < n){
        int result = arr[e] - arr[s];
        if(result < m) e++;
        else{
            ans = min(ans, result);
            s++;
        }
    }
    cout << ans << "\n";
    return 0;
}