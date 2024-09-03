#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, k;
vector<int> ans;
vector<int> visited(200010);
queue<tuple<int, int>> q;

void bfs(){
    q.push({0, n});
    visited[n] = 0;
    while(!q.empty()) {
        auto [count, now] = q.front();
        q.pop();
        if (now == k) {
            ans.push_back(count);
            continue;
        }
        if (now + 1 <= 200000 && (visited[now + 1] == 0 || visited[now + 1] == visited[now] + 1)) {
            visited[now + 1] = visited[now] + 1;
            q.push({count + 1, now + 1});
        }
        if (now - 1 >= 0 && (visited[now - 1] == 0 || visited[now - 1] == visited[now] + 1)) {
            visited[now - 1] = visited[now] + 1;
            q.push({count + 1, now - 1});
        }
        if (now * 2 <= 200000 && (visited[now * 2] == 0 || visited[now * 2] == visited[now] + 1)) {
            visited[2 * now] = visited[now] + 1;
            q.push({count + 1, now * 2});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    bfs();
    cout << ans.front() << "\n";
    cout << ans.size() << "\n";
    return 0;
}