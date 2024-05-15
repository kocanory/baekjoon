#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, l, r, l_val, r_val, answer = INT_MAX; 
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    l = 0;
    r = n - 1;
    while(l < r){
        int val = arr[l] + arr[r];
        if(abs(val) < abs(answer)){
            answer = val;
            l_val = arr[l];
            r_val = arr[r];
        }
        if(val == 0) break;
        if(val >= 0) r--;
        else l++;
    }
    cout << l_val << " " << r_val << "\n"; 
    return 0;
}