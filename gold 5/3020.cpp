#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, h, cnt;
long long Min = LLONG_MAX;
vector<long long> bottom, top;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> h;
    bottom.assign(h + 1, 0);
    top.assign(h + 1, 0);
    
    for(int i = 0;i < n / 2;i++){
        int a, b;
        cin >> a >> b;
        bottom[a]++;
        top[h - b + 1]++;
    }
    
    for(int i = h - 1;i >= 1;i--) bottom[i] += bottom[i + 1];
    for(int i = 1;i <= h;i++){
        top[i] += top[i - 1];
        if(bottom[i] + top[i] < Min){
            Min = bottom[i] + top[i];
            cnt = 1;
        }
        else if(bottom[i] + top[i] == Min){
            cnt++;
        }
    }
    cout << Min << " " << cnt << "\n";
    return 0;
}