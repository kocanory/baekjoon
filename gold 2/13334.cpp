#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, d, ans = 0;
vector<pair<int, int>> arr;
priority_queue<int> pq;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, {0, 0});
    
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {min(a, b), max(a, b)};
    }

    cin >> d;
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(auto [s, e] : arr){
        if(e - s <= d) pq.push(-s);
        else continue;
        
        while(!pq.empty()){
            if(-pq.top() < e - d) pq.pop();
            else{
                ans = max(ans, (int)pq.size());
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}