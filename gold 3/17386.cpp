#include <iostream>
#define pll pair<long long, long long>

using namespace std;

pll p1, p2, p3, p4;

int ccw(pll p1, pll p2, pll p3){
    long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;
    
    if(s > 0) return 1;
    if(s == 0) return 0;
    return -1;
}

bool isIntersect(pair<pll, pll> l1, pair<pll, pll> l2){
    pll p1 = l1.first, p2 = l1.second, p3 = l2.first, p4 = l2.second;
    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4), p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
    if(!p1p2 && !p3p4){
        if(p1 > p2) swap(p1, p2);
        if(p3 > p4) swap(p3, p4);
        return p3 <= p2 && p1 <= p4;
    }
    return p1p2 <= 0 && p3p4 <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
    cout << isIntersect({p1, p2}, {p3, p4}) << "\n";
    return 0;
}