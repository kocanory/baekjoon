#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, temp;
vector<vector<int>> ans;

void dfs(){
    if(temp.size() >= m){
        ans.push_back(temp);
        return;
    }
    for(int i = 0;i < n;i++){
        temp.push_back(arr[i]);
        dfs();
        temp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];
    
    dfs();
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(auto &a : ans){
        for(auto &num : a)
            cout << num << " ";
        cout << "\n";
    }
    
    return 0;
}