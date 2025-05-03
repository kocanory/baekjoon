#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<int> arr;

void dfs(int sum){
    if(arr.size() == 2){
        ans = max(ans, sum);
        return;
    }
    
    for(int i = 1;i < arr.size() - 1;i++){
        int val = arr[i - 1] * arr[i + 1], now = arr[i];
        arr.erase(arr.begin() + i);
        dfs(sum + val);
        arr.insert(arr.begin() + i, now);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    dfs(0);
    
    cout << ans;
    
    return 0;
}