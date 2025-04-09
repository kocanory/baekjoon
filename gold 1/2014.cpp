#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int k, n, cnt = 0, prevNum = 0;
vector<int> primes;
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k >> n;
    primes.assign(k, 0);
    
    for(int i = 0;i < k;i++){
        cin >> primes[i];
        pq.push(primes[i]);
    }

    while(cnt < n){
        while(prevNum == pq.top()) pq.pop();
        for(auto p : primes){
            long long res = (long long)p * pq.top();
            if(res > INT_MAX) break;
            pq.push(res);
        }
        prevNum = pq.top(); pq.pop();
        cnt++;
    }
    cout << prevNum;
    return 0;
}