#include <iostream>
#include <vector>

using namespace std;

void make(vector<long long> &vec, int count, string num, int index)
{
    if(num.length() >= count)
        {
            vec.push_back(stol(num));
            return;
        }
        
    for(int i = 0;i <= index && index >= 0;i++)
    {
        make(vec, count, num + to_string(i), i - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr;
    for(int i = 1 ;i<11;i++)
        make(arr, i, "", 9);
    if(arr.size() <= n)
        cout << -1 << endl;
    else
        cout << arr[n] << endl;
    return 0;
}