#include <iostream>
#include <vector>

using namespace std;

int k, cnt = 0;
vector check(7368787 + 1, true);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i = 2;i <= 7368787;i++) {
       if (check[i]) {
           cnt++;
           if (cnt == k) {
               cout << i;
               break;
           }
           for (int j = i;j <= 7368787;j += i)
               check[j] = false;
       }
    }

    return 0;
}