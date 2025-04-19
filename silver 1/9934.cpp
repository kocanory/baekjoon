#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int k;
vector<int> arr;
vector<vector<int>> ans;

void solve(int left, int right, int level){
    if(left <= right){
        int mid = (left + right) / 2;
        ans[level].push_back(arr[mid]);
        solve(left, mid - 1, level + 1);
        solve(mid + 1, right, level + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    int s = pow(2, k) - 1;
    arr.assign(s, 0);
    ans.assign(k, vector<int>());
    
    for(int i = 0;i < s;i++)  cin >> arr[i];
    solve(0, s - 1, 0);
    
    for(auto a : ans){
        for(auto n : a)
            cout << n << " ";
        cout << "\n";
    }

    return 0;
}