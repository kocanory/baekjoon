#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

string n;
int k;

int bfs() {
    queue<string> q;
    q.push(n);
    int Max = 0, cnt = 0;

    while (!q.empty() && cnt < k) {
        int size = q.size();
        unordered_map<int, bool> check;

        for (int l = 0; l < size; l++) {
            auto s = q.front(); q.pop();
            for (int i = 0;i < n.size();i++)
                for (int j = i + 1;j < n.size();j++) {
                    swap(s[i], s[j]);
                    if (!check[stoi(s)]) {
                        if (cnt == k - 1)
                            Max = max(Max, stoi(s));
                        check[stoi(s)] = true;
                        q.push(s);
                    }
                    swap(s[j], s[i]);
                }
        }
        cnt++;
    }
    return cnt < k ? -1 : Max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    if (n.size() == 1 || (n.size() == 2 && n.back() == '0'))
        cout << -1;
    else
        cout << bfs();

    return 0;
}