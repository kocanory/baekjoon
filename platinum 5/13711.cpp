#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> A, B, dp;

int lis(){
    for(auto i : A){
        if(dp.empty() || dp.back() < i) dp.push_back(i);
        else{
            auto pos = lower_bound(dp.begin(), dp.end(), i);
            *pos = i;
        }
    }
    return dp.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    A.assign(n, 0);
    B.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> A[i];
    for(int i = 0, x;i < n;i++){
        cin >> x;
        B[x - 1] = i;
    }
    
    for(int i = 0;i < n;i++) A[i] = B[A[i] - 1];
    cout << lis() << "\n";
    return 0;
}