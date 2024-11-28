#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
vector<string> arr;

int checkTail(int row){
    int ret = 0;
    for(int j = 0;j < n;j++){
        int headCnt = 0;
        for(int i = 0;i < n;i++){
            bool head = arr[i][j] == 'H';
            if(row & (1 << i)) head = !head;
            if(head) headCnt++;
        }
        ret += min(headCnt, n - headCnt);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, "");
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    for(int i = 0;i < 1 << n;i++) ans = min(ans, checkTail(i));
    cout << ans << "\n";
    return 0;
}