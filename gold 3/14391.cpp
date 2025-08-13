#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<string> arr;

bool isHorizontal(int r, int c, int mask) {
    int idx = r * m + c;
    return (mask & (1 << idx)) != 0;
}

int calc(int mask) {
    int ret = 0;
    vector check(n, vector(m, false));

    for (int i = 0;i < n * m;i++) {
        int r = i / m, c = i % m;
        int nr = r, nc = c;
        int s = 0;

        while (nr < n && nc < m && !check[nr][nc] && isHorizontal(nr, nc, mask) == isHorizontal(r, c, mask)) {
            s *= 10;
            s += (arr[nr][nc] - '0');
            check[nr][nc] = true;

            if (isHorizontal(r, c, mask)) nc++;
            else nr++;
        }
        ret += s;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");

    for (int i = 0;i < n;i++) cin >> arr[i];

    for (int i = 0;i < 1 << (n * m);i++)
        ans = max(ans, calc(i));
    cout << ans;
}