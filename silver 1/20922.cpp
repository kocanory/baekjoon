#include <iostream>
#include <vector>

using namespace std;

int n, k, e = 0, ans = 0;
vector<int> arr, count(100001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(int s = 0;s < n;s++){
        while(e < n && count[arr[e]] < k){
            count[arr[e]]++;
            e++;
        }
        ans = max(ans, e - s);
        if(e == n) break;
        count[arr[s]]--;
    }
    cout << ans << "\n";
    return 0;
}