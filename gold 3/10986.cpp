#include <iostream>
#include <vector>

using namespace std;
int n, m;
long long result = 0;

vector<long long> sum, count;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    sum.assign(n, 0);
    count.assign(m, 0);
    
    for(int i = 0;i < n;i++){
        int input;
        cin >> input;
        if(i > 0) sum[i] = sum[i - 1] + input;
        else sum[i] = input;
        
        if(sum[i] % m == 0) result++;
        count[sum[i] % m]++;
    }
    
    for(int i = 0;i < m;i++)
        if(count[i] > 1) result += (count[i] * (count[i] - 1) / 2);
        
    cout << result << "\n";
    return 0;
}