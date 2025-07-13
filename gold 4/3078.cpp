#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
long long ans = 0;
vector<string> arr;
vector<queue<int>> q(21);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    arr.assign(n, "");
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(int i = 0;i < n;i++){
        int l = arr[i].size();
        while(!q[l].empty() && i - q[l].front() > k) q[l].pop();
        ans += q[l].size();
        q[l].push(i);
    }
    cout << ans;
    return 0;
}