#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int k, m, n, ans;
vector<int> A, B, sumA, sumB;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k >> m >> n;
    
    A.assign(m, 0);
    B.assign(n, 0);
    
    for(int i = 0;i < m;i++) cin >> A[i];
    for(int i = 0;i < n;i++) cin >> B[i];
    
    sumA.push_back(0);
    sumB.push_back(0);
    sumA.push_back(accumulate(A.begin(), A.end(), 0));
    sumB.push_back(accumulate(B.begin(), B.end(), 0));
    
    for(int i = 0;i < m;i++){
        int sum = 0;
        for(int j = i;j < i + m - 1;j++){
            sum += A[j % m];
            sumA.push_back(sum);
        }
    }
    
    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = i;j < i + n - 1;j++){
            sum += B[j % n];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());
    
    for(auto &a : sumA){
        int val = k - a;
        ans += upper_bound(sumB.begin(), sumB.end(), val) - lower_bound(sumB.begin(), sumB.end(), val);
    }
    cout << ans << "\n";
    return 0;
}