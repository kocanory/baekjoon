#include <iostream>
#include <vector>

using namespace std;

int n, m, s = 0, e = 0, ans;
vector<int> arr;

int solve(int mid){
    int sum = 0, cnt = 1;
    for(auto a : arr){
        if(sum + a > mid){
            cnt++;
            sum = a;
        }
        else sum += a;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        s = max(s, arr[i]);
        e += arr[i];
    }

    while(s <= e){
        int mid = (s + e) / 2;
        if(solve(mid) > m)
            s = mid + 1;
        else{
            ans = mid;
            e = mid - 1;
        }
    }
    cout << ans;
    return 0;
}