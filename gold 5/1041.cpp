#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<int> arr;
    for(int i = 0;i<6;i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    if(n == 1)
    {
        long long sum = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0 ;i < 5;i++)
            sum += arr[i];
        cout << sum << endl;
    }
    else
    {
        int a = min(arr[0], arr[5]), b = min(arr[1], arr[4]), c = min(arr[2], arr[3]);
        int min1 = min(min(a, b), c);
        int min2 = min(min(a + b, b + c), c + a);
        int min3 = a + b + c;
        cout << (long long)min1 * ((n - 2) * (n - 2) + 4 * (n - 1) * (n - 2)) + (long long)min2 * (8 * n - 12) + (long long)min3 * 4 << endl;
    }
    return 0;
}