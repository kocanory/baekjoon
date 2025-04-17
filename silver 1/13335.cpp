#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, w, l, sum = 0, ans = 0;
vector<int> arr;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> w >> l;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(auto a : arr){
        while(true){
            if(q.size() == w){
                sum -= q.front();
                q.pop();
            }
            if(sum + a <= l) break;
            q.push(0);
            ans++;
        }
        q.push(a);
        sum += a;
        ans++;
    }
    cout << ans + w;
    return 0;
}