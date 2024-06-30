#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0;
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
    
    for(int i = 0;i < n;i++){
        if(sum + 1 < arr[i]) break;
        sum += arr[i];
    }
    
    cout << sum + 1 << "\n";
    return 0;
}