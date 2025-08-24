#include <iostream>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << (n == 1 ? 'B' : 'A');
    return 0;
}