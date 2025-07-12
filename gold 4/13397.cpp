#include <iostream>
#include <vector>

using namespace std;

int n, m, ans, l = 0, r = 10000;
vector<int> arr;

bool check(int mid){
    int cnt = 1, minv = arr[0], maxv = arr[0];
    for(int i = 1;i < n;i++){
        minv = min(minv, arr[i]);
        maxv = max(maxv, arr[i]);
        if (maxv - minv <= mid) continue;
        maxv = minv = arr[i]
        cnt++;
    }
    return cnt <= m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            r = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}