#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<bool> prime, happy;

bool check_happy(int x) {
    unordered_map<int, bool> check;
    while (x != 1 && !check[x]) {
        check[x] = true;
        int tmp = 0;
        while (x) {
            tmp += ((x % 10) * (x % 10));
            x /= 10;
        }
        x = tmp;
    }
    return x == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    prime.assign(n + 1, true);
    happy.assign(n + 1, false);

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = 2 * i;j <= n;j+=i)
                prime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        happy[i] = check_happy(i);
        if (prime[i] && happy[i])
            cout << i << '\n';
    }
    return 0;
}