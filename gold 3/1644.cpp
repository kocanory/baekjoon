#include <iostream>
#include <vector>

using namespace std;

vector<int> dp, prime;
vector<bool> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    dp.assign(n + 1, 0);
    visited.assign(n + 1, false);
    
    for(int i = 2;i <= n;i++){
        if(!visited[i])
        {
            prime.push_back(i);
            dp[i]++;    
        }
        for(int j = 2 * i;j <= n;j += i)
            visited[j] = true;
    }
    
    for(int i = 0;i < prime.size();i++){
        long long sum = prime[i];
        for(int j = i + 1;j < prime.size();j++)
        {
            sum += prime[j];
            if(sum > n) break;
            dp[sum]++;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}