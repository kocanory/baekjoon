#include <iostream>
#include <vector>

using namespace std;

int t, n;

vector<int> arr;
vector<bool> visited;
vector<bool> done;
int count;

void dfs(int node){
    visited[node] = true;
    int next = arr[node];
    
    if(!visited[next]) dfs(next);
    else if(!done[next]){
        for(int i = next;i != node;i = arr[i]) count++;
        count++;
    }
    done[node] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        arr.assign(n + 1, 0);
        visited.assign(n + 1, false);
        done.assign(n + 1, false);
        count = 0;
        
        for(int i = 1;i <= n;i++) cin >> arr[i];
        
        for(int i = 1;i <= n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        cout << n - count << "\n";
    }

    return 0;
}