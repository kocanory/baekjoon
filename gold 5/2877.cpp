#include <iostream>

using namespace std;

int k;

string to_binary(int num){
    num++;
    string res = "";
    
    while(num){
        res = to_string(num % 2) + res;
        num /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    
    string conv = to_binary(k);
    
    for(int i = 1;i < conv.size();i++)
        cout << (conv[i] == '0' ? 4 : 7);

    return 0;
}