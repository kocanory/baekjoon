#include <iostream>

using namespace std;

int t, n;

int maxFibo(int n){
    if(n <= 1) return n;
    int f0 = 0, f1 = 1;
    while(true){
        int f2 = f0 + f1;
        if(f2 == n) return f2;
        if(f2 > n) return f1;
        f0 = f1, f1 = f2;
    }
}

void fibo(int n){
    if(n == 0) return;
    int m = maxFibo(n);
    fibo(n - m);
    cout << m << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        fibo(n);
        cout << "\n";
    }

    return 0;
}