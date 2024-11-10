#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

int n, k;
string str = "", tar;
unordered_map<string, bool> visited;

int bfs() {
    queue<pair<string, int>> q;
    q.push({str, 0});
    sort(str.begin(), str.end());
    tar = str;

    while(!q.empty()) {
        auto [now, cnt] = q.front(); q.pop();
        if(now == tar) return cnt;
        if(visited[now]) continue;
        visited[now] = true;
        for(int i = 0;i <= n - k;i++) {
            string temp = now.substr(i, k);
            reverse(temp.begin(), temp.end());
            q.push({now.substr(0, i) + temp + now.substr(i + k, n - i - k), cnt + 1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        str += to_string(a);
    }
    cout << bfs() << "\n";
    return 0;
}