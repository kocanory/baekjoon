#include <iostream>
#include <vector>
#include <algorithm>>

using namespace std;

int n;
vector<long long> arr, ans;

void dfs(long long num) {
    if(ans.size() == n) {
        for(auto &a : ans) cout << a << " ";
        exit(0);
    }
    if(num % 3 == 0 && find(arr.begin(), arr.end(), num / 3) != arr.end()) {
        ans.push_back(num / 3);
        dfs(num / 3);
        ans.pop_back();
    }
    if(find(arr.begin(), arr.end(), num * 2) != arr.end()) {
        ans.push_back(num * 2);
        dfs(num * 2);
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    for(int i = 0;i < n;i++) {
        ans.push_back(arr[i]);
        dfs(arr[i]);
        ans.pop_back();
    }
    return 0;
}