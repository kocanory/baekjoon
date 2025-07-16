#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    cnt.assign(n, 0);
    
    for(int i = 0;i <n;i++) cin >> arr[i];
    
    for(int i = 0;i < n;i++){
        double maxLevel = -1000000000;
        for(int j = i + 1;j < n;j++){
            double level = (arr[j] - arr[i]) / double(j - i);
            if(level > maxLevel){
                cnt[i]++;
                cnt[j]++;
                maxLevel = level;
            }
        }
    }
    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}