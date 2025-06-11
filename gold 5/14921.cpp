#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9, l, r;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    l = 0, r = n - 1;
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    while(l < r){
        int sum = arr[l] + arr[r];
        if(abs(ans) > abs(sum)) ans = sum;
        if(sum > 0) r--;
        else l++;
    }
    cout << ans;
    return 0;
}