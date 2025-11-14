#include <iostream>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    if(n == 1)
        cout << 0;
    else if(n == 2)
        cout << 2;
    else{
        long long res = 2;
        for(int i = 2;i < n;i++){
            res *= 3;
            res %= (long long)(1e9 + 9);
        }
        cout << res;
    }
    return 0;
}