#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

void dfs(int left, int right){
    if(left <= right){
        if(left == right){
            cout << arr[left] << "\n";
            return;
        }
        int index = left + 1;
        while(index <= right && arr[index] < arr[left]) index++;
        dfs(left + 1, index - 1);
        dfs(index, right);
        cout << arr[left] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(cin >> n) arr.push_back(n);
    dfs(0, arr.size() - 1);
    return 0;
}