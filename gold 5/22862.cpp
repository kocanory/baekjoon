#include <iostream>
#include <vector>

using namespace std;

int n, k, l = 0, r = 0, cnt = 0, ans = 0;
vector<bool> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    arr.assign(n, false);
    
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        arr[i] = num % 2 == 0;
    }
    
    while(r < n){
        if(cnt < k){
            if(!arr[r]) cnt++;
            r++;
            ans = max(ans, r - l - cnt);
        }
        else if(arr[r]){
            r++;
            ans = max(ans, r - l - cnt);
        }
        else{
            if(!arr[l]) cnt--;
            l++;
        }
    }
    cout << ans;
    return 0;
}