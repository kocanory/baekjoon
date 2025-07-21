#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, d, k, c, ans, cnt = 0;
vector<int> arr, check;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> d >> k >> c;
    arr.assign(n, 0);
    check.assign(d + 1, 0);
    
    for(int i = 0;i < n;i++)cin >> arr[i];
    
    for(int i = 0;i < k;i++){
        q.push(arr[i]);
        if(!check[arr[i]]) cnt++;
        check[arr[i]]++;
    }
    ans = cnt;
    
    for(int i = 0;i < n;i++){
        int now = q.front(); q.pop();
        check[now]--;
        if(!check[now]) cnt--;
        
        q.push(arr[(i + k) % n]);
        if(!check[arr[(i + k) % n]]) cnt++;
        check[arr[(i + k) % n]]++;
        
        if(!check[c]) ans = max(ans, cnt + 1);
        else ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}