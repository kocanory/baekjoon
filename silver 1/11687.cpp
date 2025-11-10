#include <iostream>
#include <climits>

using namespace std;

int m, l = 1, r = INT_MAX, ans = 0;

int check(int mid){
    int cnt = 0;
    for(int i = 5;i <= mid;i *= 5)
        cnt += (mid / i);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;

    while(l <= r){
        int mid = (l + r) / 2, c = check(mid);
        if(c >= m){
            if(c == m) ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << (ans == 0 ? -1 : ans);
    return 0;
}