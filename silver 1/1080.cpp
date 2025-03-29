#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<string> arr, res;

void change(int x, int y){
    for(int i = x;i < x + 3;i++)
        for(int j = y;j < y + 3;j++)
            arr[i][j] = !(arr[i][j] - '0') + '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, "");
    res.assign(n, "");
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < n;i++) cin >> res[i];
    
    for(int i = 0;i < n - 2;i++)
        for(int j = 0;j < m - 2;j++)
            if(arr[i][j] != res[i][j]){
                ans++;
                change(i, j);
            }

    for(int i = 0;i < n && ans != -1;i++)
        for(int j = 0;j < m && ans != -1;j++)
            if(arr[i][j] != res[i][j])
                ans = -1;
                
    cout << ans;
    return 0;
}