#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, ans = 0;
string s;
vector<int> arr;
unordered_map<string, int> idx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++){
        cin >> s;
        idx[s] = i;
    }
    
    for(int i = 0;i < n;i++){
        cin >> s;
        arr[i] = idx[s];
    }

    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
            if(arr[i] > arr[j]){
                ans++;
                break;
            }
    
    cout << ans;
    return 0;
}