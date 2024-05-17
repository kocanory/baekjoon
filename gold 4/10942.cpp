#include <iostream>
#include <vector>

using namespace std;

int n, m, s, e;
vector<int> arr;
vector<vector<bool>> palindrome;

void check_palindrome(){
    for(int i = 0;i < n;i++) palindrome[i][i] = true;
    for(int i = 0;i < n - 1;i++)
        if(arr[i] == arr[i + 1]) palindrome[i][i + 1] = true;
    
    for(int len = 3;len <= n;len++){
        for(int start = 0;start + len - 1 < n;start++){
            int end = start + len - 1;
            if(arr[start] == arr[end] && palindrome[start + 1][end - 1])
                palindrome[start][end] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    arr.assign(n, 0);
    palindrome.assign(n, vector<bool>(n, false));
    
    for(int i = 0;i < n;i++) cin >> arr[i];
    check_palindrome();
    
    cin >> m;
    while(m--){
        cin >> s >> e;
        cout << palindrome[s - 1][e - 1] << "\n";
    }
    
    return 0;
}