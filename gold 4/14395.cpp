#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

int s, t;
unordered_map<ll, bool> check;
queue<pair<ll, string>> q;
vector<char> op = {'*', '+', '-', '/'};

ll calc(ll num, int idx){
    if(idx == 0) return num * num;
    if(idx == 1) return num + num;
    if(idx == 2) return num - num;
    if(idx == 3) return num / num;
}

string bfs(){
    q.push({s, ""});
    check[s] = true;
    
    while(!q.empty()){
        auto [n, o] = q.front(); q.pop();
        if(n == t) return o;
        for(int i = 0;i < 4;i++){
            ll nxt = calc(n, i);
            if(nxt > t || nxt < 1 || check[nxt]) continue;
            q.push({nxt, o + op[i]});
            check[nxt] = true;
        }
    }
    return "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s >> t;
    cout << (s == t ? "0" : bfs());

    return 0;
}