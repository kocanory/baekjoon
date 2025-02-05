#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, max_a, a_idx, max_b, b_idx;
vector<int> a, b, ans;
bool flag = true;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    cin >> m;
    b.assign(m, 0);
    for(int i = 0;i < m;i++) cin >> b[i];
    
    while(true){
        while(true){
            if(a.empty() || b.empty()){
                flag = false;
                break;
            }
            max_a = *max_element(a.begin(), a.end());
            a_idx = distance(a.begin(), max_element(a.begin(), a.end()));
            max_b = *max_element(b.begin(), b.end());
            b_idx = distance(b.begin(), max_element(b.begin(), b.end()));
            if(max_a == max_b) break;
            if(max_a > max_b) a.erase(a.begin() + a_idx);
            else b.erase(b.begin() + b_idx);
        }
        if(!flag) break;
        ans.push_back(max_a);
        a.erase(a.begin(), a.begin() + a_idx + 1);
        b.erase(b.begin(), b.begin() + b_idx + 1);
    }
    cout << ans.size() << "\n";
    if(!ans.empty()){
        for(auto a : ans)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}