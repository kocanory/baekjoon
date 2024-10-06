#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> arr, sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr = vector<int>(n + 1);
    sum = vector<int>(n + 1);
    
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    
    for(int i = 2;i < n;i++)
        ans = max(ans, (sum[i] - sum[1]) + (sum[n - 1] - sum[i - 1]));
        
    for(int i = 2;i < n;i++)
        ans = max(ans, (sum[n] - sum[1] - arr[i]) + (sum[n] - sum[i]));
        
    for(int i = 2;i < n;i++)
        ans = max(ans, (sum[n - 1] - arr[i]) + sum[i - 1]);
    
    cout << ans << "\n";
    return 0;
}