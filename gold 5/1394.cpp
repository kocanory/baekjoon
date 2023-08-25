#include <iostream>

using namespace std;

int main()
{
    string pattern, password;
    cin >> pattern;
    cin >> password;
    int arr[200] = {0, };
    int result = 0, size = pattern.length();
    for(int i = 0;i<pattern.length();i++)
    {
        int index = pattern[i] - '!';
        if(arr[index] == 0)
            arr[index] = i + 1;
    }
    for(int i = 0;i<password.length();i++)
    {
        int index = password[i] - '!';
        result *= size;
        result += arr[index];
        result %= 900528;
    }
    cout << result << endl;
    return 0;
}