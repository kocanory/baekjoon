#include <iostream>

using namespace std;

int n, num, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--){
        cin >> num;
        for (int i = 2;i <= num;i++) {
            if (num % i == 0) {
                cnt = 0;
                while (num % i == 0) {
                    num /= i;
                    cnt++;
                }
                cout << i << " " << cnt << "\n";
            }
        }

    }

    return 0;
}