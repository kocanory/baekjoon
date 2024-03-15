#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if(n < 8){
        cout << -1 << "\n";
        return 0;
    }
    
    vector<int> answer;
    vector<int> arr(n + 1, 0);
    arr[0] = 1;
    arr[1] = 1;
    
    for(int i = 2;i <= n;i++){
        if(arr[i]) continue;
        for(int j = 2 * i;j <= n;j += i) arr[j] = 1;
    }
    
    if(n % 2){
        answer.push_back(2);
        answer.push_back(3);
        n -= 5;
    }
    else
    {
        answer.push_back(2);
        answer.push_back(2);
        n -= 4;
    }
    
    for(int k = n / 2;k >= 0;k--){
        if(arr[k] == 0 && arr[n - k] == 0){
            answer.push_back(k);
            answer.push_back(n - k);
            break;
        }
    }
    
    for(auto a : answer)
        cout << a << " ";
    cout << "\n";
    return 0;
}