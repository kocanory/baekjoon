#include <iostream>

using namespace std;

int t, n, m, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> m >> n >> x >> y;
        bool flag = true;
        for(int i = 0;i < n;i++){
            if((i * m + x - y) % n == 0){
                cout << i * m + x << "\n";
                flag = false;
                break;
            }
        }
        if(flag) cout << -1 << "\n";
    }
    return 0;
}