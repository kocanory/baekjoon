#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, cnt;
vector<long long> arr, part1, part2;

void dfs(int start, int end, vector<long long> &part, long long sum){
    if(start > end){
        part.push_back(sum);
        return;
    }
    else{
        dfs(start + 1, end, part, sum);
        dfs(start + 1, end, part, sum + arr[start]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    arr.assign(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];

    dfs(0, n / 2 - 1, part1, 0);
    dfs(n / 2, n - 1, part2, 0);
    sort(part2.begin(), part2.end());
    for(auto & p : part1){
        long long target = c - p;
        cnt += upper_bound(part2.begin(), part2.end(), target) - part2.begin();
    }
    cout << cnt << "\n";
    return 0;
}