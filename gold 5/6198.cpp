#include <iostream>
#include <vector>

using namespace std;

int n;
long long ans = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >>  n;
    while(n--){
        int num;
        cin >> num;
        
        if(arr.empty()){
            arr.push_back(num);
            continue;
        }
        
        while(!arr.empty() && arr.back() <= num)
            arr.pop_back();
            
        ans += arr.size();
        arr.push_back(num);
    }
    cout << ans;
    return 0;
}