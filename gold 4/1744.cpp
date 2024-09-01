#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0;
vector<int> p, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        if(num > 0) p.push_back(num);
        else m.push_back(num);
    }
    
    sort(p.begin(), p.end(), greater<int>());
    sort(m.begin(), m.end());
    
    if(p.size() % 2 != 0) ans += p.back();
    for(int i = 0;i < (int)p.size() - 1;i+=2){
        if(p[i + 1] == 1) ans += p[i] + p[i + 1];
        else ans += p[i] * p[i + 1];
    }
    
    if(m.size() % 2 != 0) ans += m.back();
    for(int i = 0;i < (int)m.size() - 1;i += 2)
        ans += m[i] * m[i + 1];
    
    cout << ans << "\n";
    return 0;
}