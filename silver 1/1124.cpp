#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int a, b, ans = 0;
vector<bool> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    
    check.assign(21, true);
    check[1] = false;
    
    for(int i = 2;i <= 20;i++){
        if(!check[i]) continue;
        for(int j = i * i;j <= 20;j+=i)
            check[j] = false;
    }
    
    for(int i = a;i <= b;i++){
        int now = i, cnt = 0;
        for(int j = 2;j < int(sqrt(i)) + 1;j++)
            while(now % j == 0){
                now /= j;
                cnt++;
            }
        if(now != 1)
            cnt++;
        if(check[cnt]) ans++;
    }
    cout << ans;
    return 0;
}