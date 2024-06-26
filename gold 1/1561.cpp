#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> t;
long long maxTime = 0, minTime;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    t.assign(m, 0);
    
    for(auto &a : t){
        cin >> a;
        maxTime = max(maxTime, (long long)a);
    }
    
    if(n <= m){
        cout << n << "\n";
        return 0;
    }
    
    long long left = 1, right = maxTime * n;
    while(left <= right){
        long long mid = (left + right) / 2, sum = m;
        for(auto &a : t) sum += (mid / a);
        if(sum >= n){
            right = mid - 1;
            minTime = mid;
        }
        else left = mid + 1;
    }
    
    long long sum = m;
    for(auto &a : t) sum += ((minTime - 1) / a);
    
    for(int i = 0;i < m;i++){
        if(minTime % t[i] == 0) sum++;
        if(sum == n){
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}