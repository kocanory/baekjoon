#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m, p, l;
string command;

priority_queue<pair<int, int>> hard;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> easy;
unordered_map<int, int> cnt;

void checkCommand(string command) {

    if(command == "add") {
        cin >> p >> l;
        hard.push({l, p});
        easy.push({l, p});
        cnt[p]++;
    }
    else if(command == "recommend") {
        cin >> l;
        if(l == 1) cout << hard.top().second << "\n";
        else cout << easy.top().second << "\n";
    }
    else {
        cin >> p;
        cnt[p]--;
        while(!hard.empty() && cnt[hard.top().second] <= 0) hard.pop();
        while(!easy.empty() && cnt[easy.top().second] <= 0) easy.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0;i < n;i++) {
        cin >> p >> l;
        hard.push({l, p});
        easy.push({l, p});
        cnt[p]++;
    }

    cin >> m;
    for(int i = 0;i < m;i++) {
        cin >> command;
        checkCommand(command);
    }
    return 0;
}