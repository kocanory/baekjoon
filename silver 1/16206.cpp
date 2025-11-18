#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num, idx = 0, ans = 0;
vector<int> arr1, arr2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> num;
        if(num < 10) continue;
        if(num == 10) ans++;
        else if(num % 10 == 0) arr1.push_back(num);
        else arr2.push_back(num);
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());

    while(m && idx < arr1.size()){
        int val = arr1[idx], b = val / 10;
        if(val % 10 == 0 && b - 1 <= m) {
            ans += b;
            m -= (b - 1);
        }
        else if(val % 10 && b <= m) {
            ans += b;
            m -= b;
        }
        else{
            ans += m;
            break;
        }
        idx++;
    }
    cout << ans;
    return 0;
}