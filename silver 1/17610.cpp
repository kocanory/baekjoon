#include <iostream>
#include <vector>

using namespace std;

int n, sum = 0, ans = 0;
vector<int> arr;
vector<bool> check;

void dfs(int idx, int s){
    if(idx == n){
        if(s >= 0) check[s] = true;
        return;
    }
    
    dfs(idx + 1, s);
    dfs(idx + 1, s + arr[idx]);
    dfs(idx + 1, s - arr[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    check.assign(sum + 1, false);
    
    dfs(0, 0);
    
    for(int i = 1;i <= sum;i++)
        if(!check[i])
            ans++;
    
    cout << ans;
    return 0;
}