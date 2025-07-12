#include <iostream>
#include <vector>

using namespace std;

int n, sum = 0, cnt = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sum += arr[i];
        cnt += arr[i] / 2;
    }
    
    if(sum % 3 || cnt < sum / 3) cout << "NO";
    else cout << "YES";

    return 0;
}