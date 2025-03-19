#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0;
vector<int> check(1001);
vector<pair<int, int>> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, {0, 0});
    
    for(int i = 0;i < n;i++) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());
    
    for(auto &a : arr){
        for(int i = a.second;i >= 1;i--){
            if(!check[i]){
                check[i] = a.first;
                break;
            }
        }
    }

    for(auto c: check) ans += c;
    cout << ans << "\n";
    return 0;
}