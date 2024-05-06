#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
long long sum = 0;
multiset<int> bag;
vector<pair<int, int>> jewerly;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.second < b.second;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    jewerly.assign(n, pair<int, int>());
    
    for(int i = 0;i < n;i++){
        cin >> jewerly[i].first >> jewerly[i].second;
    }
    
    for(int i = 0;i < k;i++){
        int b;
        cin >> b;
        bag.insert(b);
    }
    
    sort(jewerly.begin(), jewerly.end(), comp);
    
    for(auto &j : jewerly){
        auto index = bag.lower_bound(j.first);
        if(index != bag.end()){
            sum += j.second;
            bag.erase(index);
        }
        if(bag.empty()) break;
    }
    cout << sum << "\n";
    return 0;
}