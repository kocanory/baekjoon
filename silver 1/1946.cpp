#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<pair<int, int>> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n, {0, 0});
        
        for(int i = 0;i < n;i++) cin >> arr[i].first >> arr[i].second;
        
        sort(arr.begin(), arr.end());
        int low = arr[0].second, cnt = 1;
        
        for(int i = 1;i < n;i++)
            if(arr[i].second < low){
                low = arr[i].second;
                cnt++;
            }
        cout << cnt << "\n";
    }
    return 0;
}