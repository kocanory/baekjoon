#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<int> bag;
vector<pair<int, int>> jewerly;

long long calc(){
    sort(bag.begin(), bag.end());
    sort(jewerly.begin(), jewerly.end());
    
    priority_queue<int> pq;
    int idx = 0;
    long long sum = 0;
    
    for(auto b : bag){
        while(idx < n && b >= jewerly[idx].first){
            pq.push(jewerly[idx].second);
            idx++;
        }
        
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    bag.assign(k, 0);
    jewerly.assign(n, pair<int, int>());
    
    for(int i = 0;i < n;i++){
        cin >> jewerly[i].first >> jewerly[i].second;
    }
    
    for(int i = 0;i < k;i++){
        cin >> bag[i];
    }
    cout << calc() << "\n";
    return 0;
}