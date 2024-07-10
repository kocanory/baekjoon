#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++) {
        int s, e;
        cin >> s >> e;
        arr.push_back({s, e});
    }
    sort(arr.begin(), arr.end());

    pq.push(arr[0].second);
    for(int i = 1;i < arr.size();i++){
        if(arr[i].first >= pq.top()){
            pq.pop();
            pq.push(arr[i].second);
        }
        else pq.push(arr[i].second);
    }
    cout << pq.size() << "\n";
    return 0;
}