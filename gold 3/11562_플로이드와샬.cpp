#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n + 1, vector(n + 1, (int)1e9));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][a] = dist[b][b] = dist[a][b] = 0;
        dist[b][a] = (c ? 0 : 1);
    }

    for (int k = 1;k <= n;k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << "\n";
    }
    return 0;
}