#include <iostream>
#include <vector>

using namespace std;

int n, d, k, c, maxCnt = 0;
vector<int> arr;
vector<bool> check;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> d >> k >> c;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(int i = 0;i < n;i++){
        check.assign(d + 1, false);
        int dup = 0;
        for(int j = i;j < i + k;j++){
            if(!check[arr[j % n]]) check[arr[j % n]] = true;
            else dup++;
        }
        maxCnt = max(maxCnt, k - dup + !check[c]);
    }
    cout << maxCnt;
    return 0;
}