#include <iostream>

using namespace std;
#define pii pair<int, int>

pii l1, l2, l3;

int ccw(pii a, pii b, pii c){
    int s = a.first * b.second + b.first * c.second + c.first * a.second;
    s -= (b.first * a.second + c.first * b.second + a.first * c.second);
    
    if(s > 0) return 1;
    if(s == 0) return 0;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> l1.first >> l1.second;
    cin >> l2.first >> l2.second;
    cin >> l3.first >> l3.second;
    
    cout << ccw(l1, l2, l3) << "\n";
    return 0;
}