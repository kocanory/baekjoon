#include <iostream>
#include <queue>

using namespace std;

int n, p, d, ans = 0;
int check[10001];
priority_queue<pair<int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> p >> d;
        pq.push({p, d});
    }
    
    while(!pq.empty()){
        auto[p, d] = pq.top(); pq.pop();
        while(d--){
            if(!check[d]){
                check[d] = true;
                ans += p;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}