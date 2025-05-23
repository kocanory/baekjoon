#include <iostream>
#include <vector>

using namespace std;

int n, k, cnt = 0;
vector<int> arr;

void dfs(int sum){
    if(sum > n) return;
    if(sum == n){
        cnt++;
        if(cnt == k){
            for(int i = 0;i < arr.size();i++){
                cout << arr[i];
                if(i < arr.size() - 1) cout << '+';
            }
        }
        return;
    }
    
    for(int i = 1;i <= 3;i++){
        arr.push_back(i);
        dfs(sum + i);
        arr.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    
    dfs(0);
    
    if(cnt < k) cout << -1;

    return 0;
}