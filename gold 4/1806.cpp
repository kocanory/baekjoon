#include <iostream>
#include <vector>

using namespace std;

int n, s, answer = 1e9;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    arr.assign(n, 0);
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    int start = 0, end = 0, sum = arr[start];
    while(start <= end && end < n){
        if(sum < s) sum += arr[++end];
        else{
            answer = min(answer, end - start + 1);
            sum -= arr[start++];
        }
    }
    
    if(answer == 1e9) answer = 0;
    cout << answer << "\n";
    return 0;
}