#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long ans = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    for(int i = 0;i < n - 2;i++){
        int left = i + 1, right = n - 1;
        while(left < right){
            int val = arr[i] + arr[left] + arr[right];
            if(val > 0) right--;
            else{
                if(val == 0){
                    if(arr[left] == arr[right]) ans += right - left;
                    else{
                        int idx = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), arr[right]));
                        ans += right - idx + 1;
                    }
                }
                left++;
            }
        }
    }
    cout << ans;
    return 0;
}