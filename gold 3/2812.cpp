#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt = 0;
string num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    cin >> num;
    
    vector<char> arr;
    
    for(auto n : num){
        while(!arr.empty() && cnt < k && n > arr.back()){
            cnt++;
            arr.pop_back();
        }
        arr.push_back(n);
    }
    
    while(cnt < k){
        cnt++;
        arr.pop_back();
    }
    
    for(auto a : arr)
        cout << a;
    return 0;
}