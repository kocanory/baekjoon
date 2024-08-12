#include <iostream>
#include <queue>

using namespace std;

int n, ans = 0;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        pq.push(-a);
    }
    
    while(pq.size() != 1){
        int a = -pq.top(); pq.pop();
        int b = -pq.top(); pq.pop();
        ans += (a + b);
        pq.push(-(a + b));
    }
    cout << ans << "\n";
    return 0;
}