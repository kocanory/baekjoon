#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num, ans = 0;
vector<int> pos, neg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> num;
        if(num > 0) pos.push_back(num);
        else neg.push_back(-num);
    }
    
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    
    for(int i = pos.size() - 1;i >= 0;i -= m) ans += pos[i] * 2;
    for(int i = neg.size() - 1;i >= 0;i -= m) ans += neg[i] * 2;
    
    if(!pos.empty() && !neg.empty()){
        if(pos.back() > neg.back()) ans -= pos.back();
        else ans -= neg.back();
    }
    else if(!pos.empty()) ans -= pos.back();
    else ans -= neg.back();
    cout << ans;

    return 0;
}