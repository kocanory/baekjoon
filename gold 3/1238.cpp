#include <iostream>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

map<int, vector<tuple<int, int>>> v;

void dijkstra(int start, int end, int &ret)
{
    vector<int> cost(1001, 1e9);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    pq.push({0, start});
    cost[start] = 0;
    while(!pq.empty())
    {
        auto[now_cost, now] = pq.top();
        pq.pop();
        if(now == end)
        {
            ret = cost[now];
            break;
        }
        for(auto n : v[now])
        {
            auto[next_cost, next] = n;
            next_cost += now_cost;
            if(cost[next] > next_cost)
            {
                cost[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
        
    }
}
int main()
{
    int n, m, x, answer = -1;
    
    cin >> n >> m >> x;
    
    for(int i = 0;i < m; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        v[s].push_back({t, e});
    }
    
    for(int s = 1;s <= n;s++)
    {
        int go = 0, back = 0;
        dijkstra(s, x, go);
        dijkstra(x, s, back);
        if(answer < go + back)
            answer = go + back;
    }
    cout << answer << endl;
    return 0;
}