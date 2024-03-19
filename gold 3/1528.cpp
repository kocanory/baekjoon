#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dp(1000001, -1);
vector<int> gold;
queue<int> q;

void print(int k){
    if(k == 0) return;
    print(dp[k]);
    cout << k - dp[k] << " ";
}

int main()
{
    int n;
    cin >> n;
    for(int i = 2;i < 200;i++){
        int temp = i;
        vector<int> bi;
        while(temp){
            bi.push_back(temp % 2);
            temp /= 2;
        }
        
        string s = "";
        for(int j = bi.size() - 2;j >= 0;j--){
            if(bi[j] == 0) s += "4";
            else s += "7";
        }
        gold.push_back(stoi(s));
    }

    q.push(0);
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(now == n) break;
        for(auto g : gold){
            int next = now + g;
            if(next > n) continue;
            if(dp[next] == -1){
                dp[next] = now;
                q.push(next);
            }
        }
    }
    
    if(dp[n] == -1) cout << -1;
    else print(n);
    return 0;
}