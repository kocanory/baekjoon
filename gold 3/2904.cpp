#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int n, gcd = 1, cnt = 0;
vector<bool> prime(1000100, true);
vector<int> pri;
unordered_map<int, int> map;
vector<unordered_map<int, int>> dict(101);

void check(int num, int i) {
    int idx = 0;
    while (num != 1) {
        int div = pri[idx];
        while (num % div == 0) {
            num /= div;
            map[div]++;
            dict[i][div]++;
        }
        idx++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 2;i <= 1000000;i++) {
        if (!prime[i]) continue;
        pri.push_back(i);
        for (int j = i + i; j <= 1000000; j += i)
            prime[j] = false;
    }

    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        check(num, i);
    }

    for (auto &[k, v] : map) {
        v /= n;
        gcd *= pow(k, v);
    }

    for (int i = 0;i < n;i++) {
        for (auto [k, v] : map)
            if (dict[i][k] < v)
                cnt += v - dict[i][k];
    }
    cout << gcd << " " << cnt;
}