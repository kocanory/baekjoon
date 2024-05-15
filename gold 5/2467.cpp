#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, l, r, answer = INT_MAX;
vector<int> arr;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];

    for(int i = 0;i < n;i++){
        int index = lower_bound(arr.begin() + i + 1, arr.end(), -arr[i]) - arr.begin();
        if(index != n && arr[i] + arr[index] == 0){
            l = i;
            r = index;
            break;
        }
        for(int j = -1;j <= 0;j++){
            if(i < index + j && index + j < n && abs(arr[i] + arr[index + j]) < abs(answer)){
                answer = arr[i] + arr[index + j];
                l = i;
                r = index + j;
            }
        }
    }
    cout << arr[l] << " " << arr[r] << "\n";
    return 0;
}