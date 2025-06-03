#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, ans = -1;
vector<string> arr;

bool isSqaure(int num){
    return pow((int)sqrt(num), 2) == num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, "");
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            for(int x = -n;x < n;x++)
                for(int y = -m;y < m;y++){
                    if(!x && !y) continue;
                    int r = i, c = j, num = 0;
                    while(r >= 0 && r < n && c >= 0 && c < m){
                        num = num * 10 + (arr[r][c] - '0');
                        r += x, c += y;
                        if(isSqaure(num))
                            ans = max(ans, num);
                    }
                }
    cout << ans;
    return 0;
}