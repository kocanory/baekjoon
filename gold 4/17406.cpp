#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m, k, Min = 1e9;
vector<vector<int>> arr;
vector<tuple<int, int, int>> op;
vector<bool> check;

void rotate(vector<vector<int>> &v, int x, int y, int l){
    int start = v[x][y];
    for(int i = x + 1;i < x + l;i++) v[i - 1][y] = v[i][y];
    for(int j = y + 1;j < y + l;j++) v[x + l - 1][j - 1] = v[x + l - 1][j];
    for(int i = x + l - 2;i >= x;i--) v[i + 1][y + l - 1] = v[i][y + l - 1];
    for(int j = y + l - 2;j >= y;j--) v[x][j + 1] = v[x][j];
    v[x][y + 1] = start;
}

void dfs(vector<int> idx, int cnt){
    if(cnt == k){
        vector<vector<int>> tmp = arr;
        for(auto i : idx){
            auto[r, c, s] = op[i];
            for(int j = s;j > 0;j--) rotate(tmp, r - 1 - j, c - 1 - j, j * 2 + 1);
        }

        for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = 0;j < m;j++)
                sum += tmp[i][j];
            Min = min(Min, sum);
        }
        return;
    }

    for(int i = 0;i < k;i++) {
        if (!check[i]) {
            check[i] = true;
            idx.push_back(i);
            dfs(idx, cnt + 1);
            idx.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    arr.assign(n, vector<int>(m));
    check.assign(k, false);

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> arr[i][j];

    for(int i = 0;i < k;i++){
        int r, c, s;
        cin >> r >> c >> s;
        op.push_back({r, c, s});
    }

    dfs({}, 0);
    cout << Min;
    return 0;
}