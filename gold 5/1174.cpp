#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> arr;

void dfs(string num)
{
    if(num.length() > 0)
        arr.push_back(stol(num));
    
    for(int i = 0;i<10;i++)
        if(num.length() == 0 || num[num.length() - 1] - '0' > i)
            dfs(num + to_string(i));
}
int main()
{
    dfs("");
    sort(arr.begin(), arr.end());
    
    int n;
    cin >> n;
    
    if(n > arr.size())
        cout << -1 << endl;
    else
        cout << arr[n - 1] << endl;
    
    return 0;
}