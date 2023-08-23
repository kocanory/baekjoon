#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string input;
    cin >> input;
    vector<int> arr;
    for(int i = 0;i<input.length();i++)
    {
        if(input[i] == '(')
            arr.push_back(-1);
        else if(input[i] == ')')
        {
            int cnt = 0;
            while(true)
            {
                if(arr.back() == -1) 
                {   arr.pop_back();
                    break;
                }
                cnt += arr.back();
                arr.pop_back();
            }
            int n = arr.back();
            arr.pop_back();
            arr.push_back(n * cnt);
        }
        else if(i < input.length() - 1 && input[i + 1] == '(')
            arr.push_back(input[i] - '0');
        else
            arr.push_back(1);
    }
    int answer = 0;
    for(auto a : arr)
        answer += a;
    cout << answer << endl;
    return 0;
}