#include <iostream>
#include <cmath>

using namespace std;

int n;

void dfs(int len) {
    if (len < 3) {
        cout << '-';
        return;
    }
    dfs(len / 3);
    cout << string(len / 3, ' ');
    dfs(len / 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n){
        dfs(pow(3, n));
        cout << "\n";
    }
    return 0;
}