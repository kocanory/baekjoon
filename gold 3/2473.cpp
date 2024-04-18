#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
int n;
vector<long long> arr, answer(3);
long long result = LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i = 0;i < n - 2;i++){
        int start = i + 1, end = n - 1;
        while(start < end){
            long long sum = arr[i] + arr[start] + arr[end];
            if(abs(result) > abs(sum)){
                result = sum;
                answer[0] = arr[i];
                answer[1] = arr[start];
                answer[2] = arr[end];
            }
            if(sum > 0) end--;
            else start++;
        }
    }
    for(auto a : answer)
        cout << a << " ";
    return 0;
}