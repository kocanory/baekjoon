#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long result = 0;
vector<long long> S, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    S.assign(n, 0L);
    C.assign(m, 0L);
    
    cin >> S[0];
    for(int i = 1;i < n;i++)
    {
        int input;
        cin >> input;
        S[i] = S[i - 1] + input;
    }
    
    for(int i = 0;i < n;i++){
        int r = S[i] % m;
        if(r == 0) result++;
        C[r]++;
    }
    
    for(int i = 0;i < m;i++){
        if(C[i] > 1) result += (C[i] * (C[i] - 1) / 2);
    }
    cout << result << "\n";
    return 0;
}