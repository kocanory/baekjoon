#include <iostream>
#include <vector>

using namespace std;

int n, num;
vector<pair<int, int>> s;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    s.push_back({1e9, 0});
    cin >> n;
    
    for(int i = 1;i <= n;i++){
        cin >> num;
        while(s.back().first < num) s.pop_back();
        ans.push_back(s.back().second);
        s.push_back({num, i});
    }
    for(auto &a : ans) cout << a << " ";
    return 0;
}