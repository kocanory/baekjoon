#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> A;
vector<tuple<int, int, int>> M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    A.assign(n, 0);

    for(int i = 0;i < n;i++) cin >> A[i];

    cin >> m;
    for(int i = 0;i < m;i++){
        int l, r, c;
        cin >> l >> r >> c;
        M.push_back({l - 1, r - 1, c});
    }

    priority_queue<pair<int, vector<int>>> pq;
    map<vector<int>, int> dist;

    for(pq.push({dist[A] = 0, A});pq.size();){
        auto[cost, now](pq.top()); pq.pop();
        if(dist[now] >= -cost){
            for(auto& [l, r, c] : M){
                swap(now[l], now[r]);
                if(!dist.count(now) || dist[now] > c - cost)
                    pq.push({-(dist[now] = c - cost), now});
                swap(now[l], now[r]);
            }
        }
    }
    sort(A.begin(), A.end());
    cout << (dist.count(A) ? dist[A] : -1);
    return 0;
}