#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed;
    cout.precision(9);
    
    int x, y, d, t;
    cin >> x >> y >> d >> t;
    
    double dist = sqrt(x * x + y * y);
    double minTime;
    
    if(d < t) cout << dist << "\n";
    else{
        int jump = dist / d;
        minTime = dist;
        dist -= jump * d;
        
        if(jump == 0) minTime = min(minTime, min(t + d - dist, 2.0 * t));
        else minTime = min(minTime, min(jump * t + dist, (jump + 1.0) * t));
        cout << minTime << "\n";
    }
    
    return 0;
}