#include <iostream>
#include <vector>

using namespace std;

int t, n, ans;
vector<string> arr, temp;

void dfs(int idx){
    if(temp.size() == 3){
        int cnt = 0;
        for(int i = 0;i < 3;i++)
            for(int j = i + 1;j < 3;j++)
                for(int k = 0;k < 4;k++)
                    if(temp[i][k] != temp[j][k])
                        cnt++;
        ans = min(ans, cnt);
        return;
    }
    
    for(int i = idx;i < n;i++){
        temp.push_back(arr[i]);
        dfs(i + 1);
        temp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n, "");
        
        for(int i = 0;i < n;i++) cin >> arr[i];
        if(n > 32){
            cout << 0 << "\n";
            continue;
        }
        ans = 1e9;
        dfs(0);
        cout << ans << "\n";
    }

    return 0;
}