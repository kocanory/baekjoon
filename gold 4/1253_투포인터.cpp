#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    for(int i = 0;i < n;i++){
        int left = 0, right = n - 1, target = arr[i];
        while(left < right){
            if(target < arr[left] + arr[right]) right--;
            else if(target > arr[left] + arr[right]) left++;
            else{
                if(left != i && right != i){
                    ans++;
                    break;
                }
                else if(left == i) left++;
                else right--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}