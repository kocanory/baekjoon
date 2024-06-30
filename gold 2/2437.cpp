#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 1;i < arr[0];i++){
        int compare = 0;
        for(int j = 1;j < n;j++){
            if(arr[j] + compare > i) continue;
            compare += arr[j];
            if(compare == i) break;
        }
        if(compare != i){
            cout << i << "\n";
            return 0;
        }
    }
    cout << sum + 1 << "\n";
    return 0;
}