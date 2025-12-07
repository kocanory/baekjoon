#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> arr;

void dfs(int idx, int val){
    if(idx == n) return;
    if(val + arr[idx] == s) cnt++;
    dfs(idx + 1, val);
    dfs(idx + 1, val + arr[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    arr.assign(n, 0);

    for(int &a : arr) cin >> a;
    dfs(0, 0);
    cout << cnt;
    return 0;
}