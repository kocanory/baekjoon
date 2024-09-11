#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<int> v_pre, v_in;

void post_order(int start, int end, int pos){
    for(int i = start;i < end;i++){
        if(v_pre[pos] == v_in[i]){
            post_order(start, i, pos + 1);
            post_order(i + 1, end, pos + 1 + i - start);
            cout << v_pre[pos] << " ";
        }
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
        v_pre = vector<int>(n);
        v_in = vector<int>(n);
        for(int i = 0;i < n;i++) cin >> v_pre[i];
        for(int i = 0;i < n;i++) cin >> v_in[i];
        post_order(0, n, 0);
        cout << "\n";
    }
    return 0;
}