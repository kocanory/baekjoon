#include <iostream>

using namespace std;

int arr[1000001];

int dp(string str)
{
    if(str.length() == 1) return -1;
    int i, j, len = str.length(), num = stoi(str);
    int &ret = arr[num];
    if(ret != 1e9) return ret;
    bool flag = false;
    for(i = 1;i<len;i++)
    {
        for(j = 0;j + i <= len;j++)
        {
            int sub = stoi(str.substr(j, i));
            if(sub == 0) continue;
            if(dp(to_string(num - sub)) == -1)
            {
                flag = true;
                ret = min(ret, sub);
            }
        }
    }
    if(flag == false) ret = -1;
    return ret;
}
int main()
{
    string n;
    cin >> n;
    for(int i = 0;i<1000001;i++)
        arr[i] = 1e9;
    cout << dp(n);

    return 0;
}