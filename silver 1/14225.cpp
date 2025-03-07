#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1;
vector<int> arr;
vector<bool> check(2000001);

void solve(int idx, int sum){
    check[sum] = true;
    if(idx == n) return;
    solve(idx + 1, sum);
    solve(idx + 1, sum + arr[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];

    solve(0, 0);
    while(check[ans]) ans++;
    cout << ans << "\n";
    return 0;
}