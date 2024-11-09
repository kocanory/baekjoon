#include <iostream>
#include <vector>
#include <unordered_map>

int n, k, num;
long long cnt;
using namespace std;
vector<int> sum(200001);
unordered_map<int, long long> count;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    count[0] = 1;
    for(int i = 1;i <= n;i++){
        cin >> num;
        sum[i] = sum[i - 1] + num;
        cnt += count[sum[i] - k];
        count[sum[i]]++;
    }
    cout << cnt << "\n";
    return 0;
}