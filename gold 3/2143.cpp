#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, sum = 0;
long long result = 0;
vector<int> a, b, aSum, bSum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    cin >> n;
    a.assign(n, 0);
    for(int i = 0;i < n;i++)
        cin >> a[i];
    
    for(int i = 0;i < n;i++){
        sum = a[i];
        aSum.push_back(sum);
        for(int j = i + 1;j < n;j++)
        {
            sum += a[j];
            aSum.push_back(sum);
        }
    }
    
    cin >> n;
    b.assign(n, 0);
    for(int i = 0;i < n;i++)
        cin >> b[i];
    
    for(int i = 0;i < n;i++){
        sum = b[i];
        bSum.push_back(sum);
        for(int j = i + 1;j < n;j++)
        {
            sum += b[j];
            bSum.push_back(sum);
        }
    }
    
    sort(bSum.begin(), bSum.end());
    for(auto a :  aSum){
        int num = t - a;
        int start = lower_bound(bSum.begin(), bSum.end(), num) - bSum.begin();
        int end = upper_bound(bSum.begin(), bSum.end(), num) - bSum.begin();
        result += (end - start);
    }
    cout << result << "\n";
    return 0;
}