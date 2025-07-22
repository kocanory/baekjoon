#include <iostream>
#include <queue>

using namespace std;

int t, k;
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> k;
        priority_queue<long long> pq;
        ans = 0;
        
        while(k--){
            int n;
            cin >> n;
            pq.push(-n);
        }
        
        while(pq.size() > 1){
            long long sum = -pq.top(); pq.pop();
            sum += -pq.top(); pq.pop();
            ans += sum;
            pq.push(-sum);
        }
        cout << ans << "\n";
    }

    return 0;
}