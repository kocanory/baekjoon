#include <iostream>

using namespace std;

int w, h, p, q, t, wt, ht, dir = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> w >> h >> p >> q >> t;
    
    wt = t % (w * 2);
    while(wt--){
        if(p == 0 || p == w) dir = -dir;
        p += dir;
    }
    
    ht = t % (h * 2);
    dir = 1;
    while(ht--){
        if(q == 0 || q == h) dir = -dir;
        q += dir;
    }
    
    cout << p << " " << q;
    return 0;
}