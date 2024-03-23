#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<string> dp(60, "");
vector<int> price;

void bfs(int m){
    queue<tuple<string, int>> q;
    for(int i = 0;i < price.size();i++)
    {
        q.push({to_string(i), price[i]});
        dp[price[i]] = to_string(i);
    }
    
    while(!q.empty()){
        auto[now, cost] = q.front(); q.pop();
        
        for(int i = 0;i < price.size();i++){
            int n_cost = cost + price[i];
            string n_num = (now + to_string(i) >= to_string(i) + now) ? now + to_string(i) : to_string(i) + now;
            if(n_num[0] == '0') continue;
            if(n_cost > m) continue;
            if(dp[n_cost].length() > 0){
                if(dp[n_cost].length() < n_num.length()){
                    dp[n_cost] = n_num;
                    q.push({n_num, n_cost});
                }
                else if(dp[n_cost].length() == n_num.length() && dp[n_cost] < n_num){
                    dp[n_cost] = n_num;
                    q.push({n_num, n_cost});
                }
            }
            if(dp[n_cost].length() == 0) {
                dp[n_cost] = n_num;
                q.push({n_num, n_cost});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n;
    
    price.resize(n, 0);
    
    for(int i = 0;i < n;i++)
        cin >> price[i];
        
    cin >> m;
    bfs(m);
    
    string answer = dp[m];
    for(int i = m;i >= 0;i--){
        if(dp[i].length() > answer.length())
            answer = dp[i];
        else if(dp[i].length() == answer.length() && dp[i] > answer)
            answer = dp[i];
    }
    cout << answer << "\n";
    return 0;
}