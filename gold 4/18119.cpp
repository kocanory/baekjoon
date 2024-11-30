#include <iostream>
#include <vector>

using namespace std;

int n, m, compare = (1 << 27) - 1;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    arr.assign(n, 0);
    
    for(int i = 0;i <n;i++){
        string str;
        cin >> str;
        int num = 0;
        for(auto &s : str) num |= 1 << (s - 'a');
        arr[i] = num;
    }
    
    for(int i = 0;i < m;i++){
        int mode, count = 0;
        char c;
        cin >> mode >> c;
        compare ^= 1 << (c - 'a');
        for(auto a : arr) if((a & compare) == a) count++;
        cout << count << '\n';
    }
    return 0;
}