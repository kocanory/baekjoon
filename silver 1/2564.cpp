#include <iostream>
#include <vector>

using namespace std;

int x, y, n, d, a, dg, ans = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> x >> y >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++){
        cin >> d >> a;
        if(d == 1) arr[i] = a;
        else if(d == 4) arr[i] = x + a;
        else if(d == 2) arr[i] = x + y + x - a;
        else arr[i] = 2 * x + y + y - a;
    }

    cin >> d >> a;
    if(d == 1) dg = a;
    else if(d == 4) dg = x + a;
    else if(d == 2) dg = x + y + x - a;
    else dg = 2 * x + y + y - a;
    
    for(auto a : arr){
        ans += min(abs(a - dg), 2 * x + 2 * y - abs(a - dg));
    }
    cout << ans;
    return 0;
}